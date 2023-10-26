/*
ID: akhilen1
TASK: kimbits
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N{40};
int ncr[N][N];
void pascal(){
	ncr[0][0]=1;
	for(int i=1;i<N;i++)for(int j=0;j<=i;j++)
		ncr[i][j]=(ncr[i-1][j]+(j>0?ncr[i-1][j-1]:0));
}

int dp[N][N];
void solve(){
	int n, l, x;
	cin>>n>>l>>x;
	pascal();

	for(int i{};i<N;i++)dp[i][0]=1;
	for(int i{1};i<N;i++){
		for(int j{1};j<N;j++){
			dp[i][j]=dp[i][j-1]+ncr[i][j];
		}
	}

	string ans{""};

	while(x and n){
		if(dp[n-1][min(l, n-1)]>=x){
			cout<<0;
			n--;
		}else{
			cout<<1;
			x-=dp[n-1][min(l, n-1)];
			n--;
			l--;
		}
	}
	cout<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
