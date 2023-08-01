
/*
ID: akhilen1
TASK: barn1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
	int m, s, c;
	cin>>m>>s>>c;
	vector<int> a(c);

	for(int i=0;i<c;i++)cin>>a[i];

	sort(a.begin(), a.end());

	vector<int> gaps;
	for(int i=1;i<c;i++){
		if(a[i]-a[i-1]-1>0)gaps.push_back(a[i]-a[i-1]-1);
	}

	sort(gaps.begin(), gaps.end(), greater<int>());

	int ans=a[c-1]-a[0]+1;
	for(int i=0;i<min(m-1, (int)gaps.size());i++)ans-=gaps[i];
	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
