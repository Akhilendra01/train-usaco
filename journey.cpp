/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define double long double

vector<int> adj[1000005];


double dfs(int node, int par){

	double sum=0;
	for(int child: adj[node]){
		if(child!=par){
			sum+=dfs(child, node)+1;
		}
	}	
	return sum? sum/(adj[node].size()- (par!=0)): 0;

}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	for(int i=1;i<n;i++){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout<<fixed<<setprecision(12)<<dfs(1, 0);
	
	return 0;
}