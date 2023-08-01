
/*
ID: akhilen1
TASK: milk
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

typedef pair<int, int> pii;

void solve(){
	int req, n;
	cin>>req>>n;

	vector<pii> v(n);
	for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;

	sort(v.begin(), v.end());

	int ans=0;
	for(int i=0;i<n;i++){
		int val=min(v[i].second, req);
		ans+=val*v[i].first;
		req-=val;
	}
	cout<<ans<<"\n";
}

int32_t main(){

	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
