/*
ID: akhilen1
TASK: fence
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int nax{501};

int f, deg[nax];
multiset<int> gr[nax];
vector<int> res;
void dfs(int node){

	while(!gr[node].empty()){
		int child{ *gr[node].begin() };
		gr[node].erase(gr[node].find(child));
		gr[child].erase(gr[child].find(node));
		dfs(child);
	}

	res.push_back(node);
}

void solve(){
	cin>>f;
	int src{-1};
	for(int i{};i<f;i++){
		int u, v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		if(src==-1)src=u;
		gr[u].insert(v);
		gr[v].insert(u);
	}
	bool ok{false};
	for(int i{1};i<nax;i++){
		if(deg[i]%2){
			dfs(i);
			ok=true;
			break;
		}
	}
	if(!ok)dfs(src);
	reverse(begin(res), end(res));
	for(int x: res){
		cout<<x<<"\n";
	}
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
