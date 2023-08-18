/*
ID: akhilen1
TASK: agrinet
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int


const int N{100};

int n, gr[N][N];

class DSU{
private:
	int n, *par, *rank;
public:
	DSU(int n){
		this->n=n;
		par=(int*)malloc(sizeof(int)*(n+1));
		rank=(int*)malloc(sizeof(int)*(n+1));
		memset(rank, 0, sizeof(rank));
		iota(par, par+n+1, 0);
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void merge(int a, int b){
		a=find(a), b=find(b);
		if(a!=b){
			if(rank[a]<rank[b])swap(a, b);
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
};

void solve(){
	scanf("%d", &n);

	for(int i{};i<n;i++)
	for(int j{};j<n;j++)scanf("%d", &gr[i][j]);


	priority_queue<pair<int, pair<int, int>>>pq;
		
	for(int i{};i<n;i++)
	for(int j{};j<n;j++){
		if(gr[i][j])
			pq.push({-gr[i][j], {i, j}});
	}

	DSU d(n);
	int ans{};

	while(!pq.empty()){
		auto [wt, p]=pq.top();
		pq.pop();

		auto[u, v]=p;

		if(d.find(u)!=d.find(v)){
			ans-=wt;
			d.merge(u, v);
		}
	}

	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
