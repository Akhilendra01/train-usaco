/*
ID: akhilen1
TASK: inflate
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int


const int N{10000};

int m, n, mins[N], pts[N], idx[N]; 

void solve(){
	scanf("%ld %ld", &m, &n);
	for(int i{};i<n;i++)scanf("%ld %ld", pts+i, mins+i);
	
	vector<int> dp(m+1, 0);

	for(int i{};i<n;i++){
		for(int j{};j<=m;j++){
			if(j>=mins[i])
				dp[j]=max(dp[j], dp[j-mins[i]]+pts[i]);
		}
	}
	cout<<dp[m]<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}