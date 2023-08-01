/*
ID: akhilen1
TASK: skidesign
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	int ans=1e12;
	for(int st=0;st<=83;st++){
		int sum=0;
		for(int i=0;i<n;i++){
			if(a[i]<st){
				sum+=(st-a[i])*(st-a[i]);
			}
			if(a[i]>st+17){
				sum+=(a[i]-st-17)*(a[i]-st-17);
			}
		}
		ans=min(ans, sum);
	}
	cout<<ans<<"\n";
}

int32_t main(){
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
	
	return 0;
}