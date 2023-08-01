/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<int> adj[10001];
bool vis[10001];

void dfs(int node){
	vis[node]=1;
	for(int child: adj[node]){
		if(!vis[child])
			dfs(child);
	}
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	for(int i=1;i<=n;i++){
		int j; cin>>j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	int cc=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cc++;
			dfs(i);
		}
	}

	cout<<cc;

	
	return 0;
}