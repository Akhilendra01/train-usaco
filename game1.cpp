/*
ID: akhilen1
TASK: game1
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n;
vector<int> a(n);
int dp[100][100][2];

void solve(){
	cin>>n;
	a.resize(n);
	for(int i{};i<n;i++)cin>>a[i];

	memset(dp, -1, sizeof(dp));

	function<int(int, int, int)> f{
		[&](int l, int r, int turn)->int{
			if(l>r){
				return 0;
			}

			if(dp[l][r][turn]!=-1)return dp[l][r][turn];

			if(turn){
				return dp[l][r][turn]=max({
					a[l]+f(l+1, r, 1-turn),
					a[r]+f(l, r-1, 1-turn)
				});
			}else{
				return dp[l][r][turn]=min({
					f(l+1, r, 1-turn),
					f(l, r-1, 1-turn)
				});	
			}
		}
	};
	int ans{f(0, n-1, 1)};
	cout<<ans<<" "<<accumulate(begin(a), end(a), 0ll)-ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
