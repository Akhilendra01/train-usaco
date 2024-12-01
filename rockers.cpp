/*
ID: akhilen1
TASK: rockers
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int inf{(int)1e18};

int dp[25][25][25];

void solve(){
	int n, tm, m;
	cin>>n>>tm>>m;

	vector<int> a(n);
	for(int i{};i<n;i++)cin>>a[i];

	memset(dp, -1, sizeof(dp));

	function<int(int, int, int)>f{
		[&](int idx, int t, int diskId)->int{
			if(t<0){
				return -inf;
			}
			if(idx==n or diskId==m){
				return 0;
			}

			if(dp[idx][t][diskId]!=-1)return dp[idx][t][diskId];

			return dp[idx][t][diskId]=max({
				1+f(idx+1, t-a[idx], diskId),
				f(idx, tm, diskId+1),
				f(idx+1, t, diskId),
			});
		}
	};

	cout<<f(0, tm, 0)<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
