/*
ID: akhilen1
TASK: stall4
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int inf{(int)1e18};

int n, m;
int adj[405][405], par[405], vis[405];
bool reachable(int src, int sink){
	memset(par, -1, sizeof(par));
	memset(vis, 0, sizeof(vis));

	queue<int> q;
	q.push(src);
	vis[src]=1;

	while(!q.empty()){
		int node{q.front()};
		q.pop();

		for(int i{1};i<=n+m+1;i++){
			if(!vis[i] and adj[node][i]>0){
				vis[i]=1;
				q.push(i);
				par[i]=node;
			}
		}	
	}

	return vis[sink];
}

void solve(){
	cin>>n>>m;

	int src{}, sink{n+m+1};

	for(int i{1};i<=n;i++)adj[src][i]=1;
	for(int i{1};i<=m;i++)adj[i+n][sink]=1;
	
	for(int i{1};i<=n;i++){
		int k;
		cin>>k;

		for(int j{};j<k;j++){
			int v;
			cin>>v;
			adj[i][v+n]=1;	
		}
	}

	int ans{};
	while(reachable(src, sink)){
		int curflow{inf};

		for(int i{sink};i!=src;i=par[i]){
			curflow=min(curflow, adj[par[i]][i]);
		}

		for(int i{sink};i!=src;i=par[i]){
			adj[par[i]][i]-=curflow;
			adj[i][par[i]]+=curflow;
		}

		ans+=curflow;
	}

	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
