/*
ID: akhilen1
TASK: nuggets
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n;
vector<int> a;
const int N{256};
int dp[N*N+1];
void solve(){
	cin>>n;
	a.resize(n);
	for(int i{};i<n;i++)cin>>a[i];

	int g{};
	for(int i{};i<n;i++)g=__gcd(a[i], g);

	if(g!=1){
		cout<<"0\n";
		return;
	}
	

	dp[0]=1;
	for(int i{1};i<=N*N;i++){
		for(int j{};j<n;j++){
			if(i-a[j]>=0){
				dp[i]|=dp[i-a[j]];
			}
		}
	}
	
	for(int i{N*N};i>=0;i--){
		if(dp[i]!=1){
			cout<<i<<"\n";
			return;
		}
	}	
	cout<<"0\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
