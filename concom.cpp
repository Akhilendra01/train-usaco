/*
ID: akhilen1
TASK: concom
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n;
vector<pair<int, int>> gr[200];
int own[200], owned[200];

void dfs(int node){
	if(owned[node])return;
	owned[node]=1;
	for(pair<int, int> p: gr[node]){
		own[p.first]+=p.second;
		if(own[p.first]>50){
			dfs(p.first);
		}
	}
}

void solve(){
	cin>>n;

	for(int i{};i<n;i++){
		int u, v, w;
		cin>>u>>v>>w;
		gr[u].push_back({v, w});
	}

	for(int i{1};i<=100;i+=1){
		memset(own, 0, sizeof own);
		memset(owned, 0, sizeof owned);
		dfs(i);
		for(int j{1};j<=100;j+=1){
			if(i!=j and owned[j]){
				cout<<i<<" "<<j<<"\n";
			}
		}
	}

}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
