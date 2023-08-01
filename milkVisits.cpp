/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<int> adj[(int)1e5+1];
int cc[(int)1e5+1];
int cow[(int)1e5+1];

void dfs(int node, int par, int cno){
	cc[node]=cno;
	for(int child: adj[node]){
		if(child!=par)
			dfs(child, node, cno);
	}
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		char c; cin>>c;
		if(c=='H')cow[i]=1;
	}

	for(int i=1;i<n;i++){
		int  x, y;
		cin>>x>>y;
		if(cow[x]==cow[y]){
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}

	memset(cc, -1, sizeof(cc));
	int cno=0;

	for(int i=1;i<=n;i++){
		if(cc[i]==-1){
			cno++;
			dfs(i, 0, cno);
		}
	}
	

	for(int i=1;i<=m;i++){
		int start, finish, COW;
		cin>>start>>finish;
		char c; cin>>c;
		if(c=='H')COW=1;
		else COW=0;

		if(cc[start]!=cc[finish])cout<<"1";
		else{
			if(cow[start]==COW or cow[finish]==COW)cout<<"1";
			else cout<<"0";
		}

	}	

	return 0;
}