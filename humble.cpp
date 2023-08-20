/*
ID: akhilen1
TASK: humble
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int inf{(int)1e18};

void solve(){
	int k, n;
	cin>>k>>n;
	vector<int> p(k);
	for(int i{};i<k;i++)cin>>p[i];

	vector<int> dp(n+1), last(n+1);
	dp[0]=1;

	for(int i{1};i<=n;i++){
		dp[i]=inf;
		for(int j{};j<k;j++){
			while(last[j]<i and dp[last[j]]*p[j]<=dp[i-1]){
				last[j]++;
			}
			if(dp[last[j]]*p[j]>dp[i-1]){
				dp[i]=min(dp[i], dp[last[j]]*p[j]);
			}
		}
	}
	cout<<dp[n]<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}