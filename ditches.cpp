/*
ID: akhilen1
TASK: ditch
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N{201}, inf{(int)1e18};
int n, m, adj[N][N], par[N], vis[N];

bool reacheable(int st, int en){
	queue<int> q;
	q.push(st);
	memset(vis, 0, sizeof(vis));
	vis[st]=1;

	while(!q.empty()){
		int node{q.front()};
		q.pop();
		for(int i{1};i<=m;i++){
			if(adj[node][i]>0 and vis[i]==0){
				vis[i]=1;
				q.push(i);
				par[i]=node;
			}
		}
	}

	return vis[m];
}

void solve(){
	cin>>n>>m;
  for(int i{};i<n;i++){
  	int u, v, w;
  	cin>>u>>v>>w;
  	adj[u][v]+=w;
  }

  int ans{};
  while(reacheable(1, m)){
  	int curflow{inf};
  	for(int i{m};i!=1;i=par[i]){
  		curflow=min(curflow, adj[par[i]][i]);
  	}
  	for(int i{m};i!=1;i=par[i]){
  		adj[par[i]][i]-=curflow;
  		// adj[i][par[i]]+=curflow;
  	}
  	ans+=curflow;
  }
  cout<<ans<<"\n";
}


int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
