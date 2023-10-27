/*
ID: akhilen1
TASK: msquare
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int


vector<vector<int>> A(vector<vector<int>> a){
	swap(a[0], a[1]);
	return a;
}

vector<vector<int>> B(vector<vector<int>> a){
	int t1{a[0][3]}, t2{a[1][3]};

	for(int j{3};j>0;j--){
		a[0][j]=a[0][j-1];
		a[1][j]=a[1][j-1];
	}
	a[0][0]=t1;
	a[1][0]=t2;
	return a;
}

vector<vector<int>> Bt(vector<vector<int>> a){
	int t1{a[0][0]}, t2{a[1][0]};

	for(int j{0};j<3;j++){
		a[0][j]=a[0][j+1];
		a[1][j]=a[1][j+1];
	}
	a[0][3]=t1;
	a[1][3]=t2;
	return a;
}

vector<vector<int>> C(vector<vector<int>> a){
	int tmp{a[0][1]};
	a[0][1]=a[1][1];
	a[1][1]=a[1][2];
	a[1][2]=a[0][2];
	a[0][2]=tmp;
	return a;
}

vector<vector<int>> Ct(vector<vector<int>> a){
	int tmp{a[0][1]};
	a[0][1]=a[0][2];
	a[0][2]=a[1][2];
	a[1][2]=a[1][1];
	a[1][1]=tmp;
	return a;
}


void solve(){
	vector<vector<int>> a(2, vector<int>(4));
	for(int i{};i<2;i++)for(int j{};j<4;j++)cin>>a[i][j];

	reverse(begin(a[1]), end(a[1]));

	queue<vector<vector<int>>> q;
	map<vector<vector<int>>, pair<char, int>> dis;

	vector<vector<int>> src{
		{1, 2, 3, 4},
		{8, 7, 6, 5}
	};


	q.push(src);
	dis[src]={'X', 0};

	if(a==src){
		cout<<0<<"\n\n";
		return;
	}

	while(!q.empty()){
		vector<vector<int>> node{ q.front() };
		q.pop();

		vector<vector<int>> aa (A(node)), bb(B(node)), cc(C(node));
		if(!dis[aa].second){
			dis[aa].second=1+dis[node].second;
			dis[aa].first='A';
			q.push(aa);
		}
		if(!dis[bb].second){
			dis[bb].second=1+dis[node].second;
			dis[bb].first='B';
			q.push(bb);
		}
		if(!dis[cc].second){
			dis[cc].second=1+dis[node].second;
			dis[cc].first='C';
			q.push(cc);
		}
		if(aa==a or bb==a or cc==a){
			break;
		}
	}

	cout<<dis[a].second<<"\n";

	string x{};
	while(a!=src){
		if(dis[a].first=='A')a=A(a), x+='A';
		else if(dis[a].first=='B')a=Bt(a), x+='B';
		else if(dis[a].first=='C')a=Ct(a), x+='C';
	}
	reverse(begin(x), end(x));

	for(int i{};i<x.size();i++){
		if(i>0 and i%60==0)cout<<"\n";
		cout<<x[i];
	}
	cout<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
