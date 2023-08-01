/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, q; 

vector<int> adj[5001];
int weight[5001][5001];

int dfs(int node, int par, int k){
	int ans=0;
	for(int child: adj[node]){
		if(child!=par){
			if(weight[child][node]>=k){
				ans+=1+dfs(child, node, k);
			}
		}
	}
	return ans;
}

int32_t main(){

// #ifndef ONLINE_JUDGE
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;
	

	for(int i=1;i<n;i++){
		int x, y, r;
		cin>>x>>y>>r;

		adj[x].push_back(y);
		adj[y].push_back(x);

		weight[x][y]=r;
		weight[y][x]=r;

	}

	while(q--){
		int k, v;
		cin>>k>>v;
		cout<<dfs(v, 0, k)<<"\n";
	}
	
	return 0;
}