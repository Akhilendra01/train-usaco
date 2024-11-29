/*
ID: akhilen1
TASK: shopping
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int
#define pii pair<int, int>

class offer{
public:
  int n, p;
  vector<pii> v;
  vector<int> z;
  offer(int n): n(n){
    v.resize(n);
    z.resize(5);
  }

  void input(){
  	for(int i{};i<n;i++){
  		cin>>v[i].first>>v[i].second;
  	}
  	cin>>p;
  }
};

class product{
public:
  int c, p, q;
  product(int c, int p, int q): c(c), p(p), q(q){}
};

int dp[6][6][6][6][6][100];

void solve(){
	int s, b;
	cin>>s;

	vector<offer*> offers(s);
	for(int i{};i<s;i++){
		int n;
		cin>>n;
		offers[i]=new offer(n);
		offers[i]->input();
	}


	cin>>b;
	vector<product*>prods(b);

	for(int i{};i<b;i++){
		int c, p, q;
		cin>>c>>q>>p;
		prods[i]=new product(c, p, q);
	}

	map<int, int> compress;
	for(int i{};i<b;i++)compress[prods[i]->c];


	for(int i{};i<s;i++){
		for(int j{};j<offers[i]->n;j++){
			compress[offers[i]->v[j].first];
		}
	}

	int val{};
	for(auto&[x, y]: compress){
		y=val++;
	}

	for(int i{};i<b;i++)prods[i]->c=compress[prods[i]->c];
	for(int i{};i<s;i++){
		for(int j{};j<offers[i]->n;j++){
			offers[i]->v[j].first=compress[offers[i]->v[j].first];
			offers[i]->z[offers[i]->v[j].first]=offers[i]->v[j].second;
		}
	}

	vector<int>prices(5), req(5);
	for(int i{};i<b;i++){
		prices[prods[i]->c]=prods[i]->p;
		req[prods[i]->c]=prods[i]->q;
	}

	memset(dp, -1, sizeof(dp));

	function<int(int, vector<int>)>f{
		[&](int idx, vector<int> qty)->int{

			for(int i{};i<5;i++){
				if(qty[i]<0)return (int)1e8;
			}

			if(idx==(int)offers.size()){
				int ans{};
				for(int i{};i<5;i++)ans+=qty[i]*prices[i];
				return ans;
			}

			if(dp[qty[0]][qty[1]][qty[2]][qty[3]][qty[4]][idx]!=-1)
				return dp[qty[0]][qty[1]][qty[2]][qty[3]][qty[4]][idx];

			vector<int> qty_next(5);
			for(int i{};i<5;i++){
				qty_next[i]=qty[i]-offers[idx]->z[i];
			}

			if(qty_next!=qty){
				return dp[qty[0]][qty[1]][qty[2]][qty[3]][qty[4]][idx]=min({
					offers[idx]->p+f(idx, qty_next),
					f(idx+1, qty)
				});
			}else{
				return dp[qty[0]][qty[1]][qty[2]][qty[3]][qty[4]][idx]=f(idx+1, qty);
			}
		}
	};
	vector<int> init(5);
	for(int i{};i<5;i++){
		init[i]=req[i];
	}
	cout<<f(0, init)<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
