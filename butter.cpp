/*
ID: akhilen1
TASK: butter
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int

int n, p, c, freq[801];
vector<pair<int, int>> gr[801];

int dijk(int src){
	vector<int> d(p+1, 1e9);
	priority_queue<pair<int, int>> pq;
	d[src]=0;
	pq.push({0, src});
	while(!pq.empty()){
		auto [dist, node]{pq.top()};
		pq.pop();
		dist=-dist;
		for(auto [child, wt]: gr[node]){
			int val {dist+wt};
			if(d[child]>val){
				d[child]=val;
				pq.push({-val, child});
			}
		}
	}	

	int val{};
	for(int i{1};i<=p;i++)val+=freq[i]*d[i];
	return val;
}

void solve(){
	cin>>n>>p>>c;
	for(int i{};i<n;i++){
		int x; cin>>x;
		freq[x]++;
	}
	for(int i{};i<c;i++){
		int u, v, w;
		cin>>u>>v>>w;
		gr[u].push_back({v, w});
		gr[v].push_back({u, w});
	}

	int ans{(int)1e9};
	for(int i{1};i<=p;i++){
		ans=min(ans, dijk(i));
	}
	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
