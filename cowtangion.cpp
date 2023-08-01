/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


vector<int> adj[(int)1e5+1];

int dfs(int node, int par){
	int children=adj[node].size()-1;
	
	int days=0;
	int count=1;
	while(count<children+1){
		count*=2;
		days++;
	}

	for(int child: adj[node]){
		if(child!=par){
			days+=dfs(child, node);
		}
	}
	return days+children;
}


int32_t main(){

// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	for(int i=1;i<n;i++){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	adj[1].push_back(0);
	cout<<dfs(1, 0);

	
	return 0;
}