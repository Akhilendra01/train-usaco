/*
ID: akhilen1
TASK: numtri
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int

#define MAX_N 1001

int n;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];


const int inf=1e18;

int f(int i, int j){
	if(i==n+1)return 0;
	if(j>i)return -inf;
	if(dp[i][j]!=-1)return dp[i][j];

	return dp[i][j]=max({
		a[i][j]+f(i+1, j),
		a[i][j]+f(i+1, j+1)
	});
}

void solve(){
	cin>>n;

	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;

	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++){
		cin>>a[i][j];
	}

	cout<<f(1, 1)<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
