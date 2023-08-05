/*
ID: akhilen1
TASK: money
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
	int v, n;
	cin>>v>>n;

	vector<int> a(v+1);
	for(int i{1};i<=v;i++)cin>>a[i];

	vector<vector<int>> dp(n+1, vector<int>(v+1));

	for(int i{};i<=v;i++)dp[0][i]=1;

	for(int i{1};i<=n;i+=1){
		for(int j{1};j<=v;j+=1){
			if(i>=a[j])
				dp[i][j]+=dp[i-a[j]][j]+dp[i][j-1];
			else
				dp[i][j]+=dp[i][j-1];
		}
	}
	cout<<dp[n][v]<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
