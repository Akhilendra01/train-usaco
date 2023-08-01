/*
ID: akhilen1
TASK: holstein
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	int m;
	cin>>m;

	vector<vector<int>> mat(m, vector<int>(n)); 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)cin>>mat[i][j];
	}
	
	int ans=1e9;
	vector<int> res;

	for(int mask=0;mask<(1<<m);mask++){
		vector<int> b(n);
		int c{};
		vector<int> cur;
		for(int j=0;j<16;j++){
			if((mask>>j)&1){
				c++;
				cur.push_back(j);
				for(int i=0;i<n;i++)b[i]+=mat[j][i];
			}
		}

		bool ok=1;
		for(int i=0;i<n;i++){
			if(b[i]<a[i]){
				ok=0;
				break;
			}
		}
		if(ok){
			if(ans>c){
				ans=c;
				res=cur;
			}
		}
	}
	cout<<ans<<" ";
	for(int i=0;i<res.size();i++){
		cout<<res[i]+1;
		if(i!=res.size()-1)cout<<" ";
	}
	cout<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
