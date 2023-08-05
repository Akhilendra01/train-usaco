/*
ID: akhilen1
TASK: nocows
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int mod{9901};
int dp[250][101];

void solve(){
	int n, h;
	cin>>n>>h;

	for(int i{1};i<=n;i+=2){
	for(int j{1};j<=h;j+=1){
			if(i==1){
				dp[i][j]=1;
				continue;
			}
			for(int k=1;k<i;k+=2){
				dp[i][j]+=dp[k][j-1]*dp[i-1-k][j-1];
				dp[i][j]%=mod;
			}
		}
	}
	cout<<(dp[n][h]-dp[n][h-1]+mod)%mod<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
