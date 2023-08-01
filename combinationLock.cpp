/*
ID: akhilen1
TASK: combo
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n; 
bool match(vector<int>&a, vector<int>&b){
	vector<int> d(3);
	for(int i=0;i<3;i++)d[i]=min((a[i]-b[i]+n)%n, (b[i]-a[i]+n)%n);
	for(int i=0;i<3;i++)if(d[i]>2)return false;
	return true;
}

void solve(){
	cin>>n;

	vector<int> v1(3), v2(3);

	cin>>v1[0]>>v1[1]>>v1[2];
	cin>>v2[0]>>v2[1]>>v2[2];

	int ans=0;
	for(int ai=1;ai<=n;ai++)
	for(int bi=1;bi<=n;bi++)
	for(int ci=1;ci<=n;ci++)
	{
		vector<int> a{ai, bi, ci};

		bool ok=match(a, v1);
		if(ok){
			ans++;
			continue;
		}

		ok=match(a, v2);
		if(ok)ans++;
	}
	cout<<ans<<"\n";
}

int32_t main(){

	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
	
	return 0;
}
