/*
ID: akhilen1
TASK: comehome
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int inf{(int)1e10};

void solve(){
	int n;
	cin>>n;

	map<char, vector<pair<char, int>>> gr;

	for(int i{};i<n;i++){
		char u, v;
		int w;
		cin>>u>>v>>w;
		gr[u].push_back({v, w});
		gr[v].push_back({u, w});
	}

	map<int, int> ans;
	for(char c{'a'};c<='z';c++)ans[c]=inf;
	for(char c{'A'};c<'Z';c++)ans[c]=inf;

	priority_queue<pair<int, char>> pq;
	
	pq.push({0, 'Z'});
	ans['Z']=0;

	while(!pq.empty()){
		auto [d, node]=pq.top();
		d*=-1;
		pq.pop();

		for(auto [child, wt]: gr[node]){
			int val{d+wt};
			if(ans[child]>val){
				ans[child]=val;
				pq.push({-val, child});
			}
		}
	}

	int res{inf};
	char ch{'x'};

	for(char c{'A'};c<'Z';c++){
		if(res>ans[c]){
			res=ans[c];
			ch=c;
		}
	}

	cout<<ch<<" "<<res<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
