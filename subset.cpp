/*
ID: akhilen1
TASK: subset
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int


void solve(){
	int n;
	cin>>n;

	int sum=n*(n+1)/2;
	if(sum%2){
		cout<<"0\n";
		return;
	}

	vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));

	function<int(int, int)> f=[&](int num, int val)->int{
		if(num==0){
			return val==sum/2;
		}
		if(val>sum/2){
			return 0;
		}
		if(dp[num][val]!=-1)return dp[num][val];
		return dp[num][val]=f(num-1, val+num)+f(num-1, val);
	};

	cout<<f(n, 0)/2<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
