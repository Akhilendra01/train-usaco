/*
ID: akhilen1
TASK: money
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int v, n;
vector<int> a;
int dp[10001][25];

int f(int val, int idx){
	if(idx==v){
		return val==n;
	}
	if(val>n){
		return 0;
	}
	if(dp[val][idx]!=-1)return dp[val][idx];
	return dp[val][idx]=f(val, idx+1)+f(val+a[idx], idx);
}

void solve(){

	memset(dp, -1, sizeof dp);

	cin>>v>>n;
	a.resize(v);
	for(int i{};i<=v;i+=1){
		cin>>a[i];
	}

	cout<<f(0, 0)<<"\n";
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
