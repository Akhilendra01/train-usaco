/*
ID: akhilen1
TASK: stamps
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int

void solve(){
	int k, n;
	cin>>k>>n;

	static int a[50], dp[200*10000+5];
	
	for(int i{};i<n;i++)cin>>a[i];

	memset(dp, 0x3F, sizeof dp);

	dp[0]=0;

	for(int i{};i<=k*1e4;i++)
	for(int j{};j<n;j++){
		if(dp[i]>k){
			cout<<i-1<<"\n";
			return;
		}
		dp[i+a[j]]=min(dp[i+a[j]], 1+dp[i]);
	}	
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
