/*
ID: akhilen1
TASK: sort3
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
	
	vector<int> freq(4);
	for(int i=0;i<n;i++)freq[a[i]]++;

	vector<vector<int>> swap(4, vector<int> (4, 0));
	for(int i=0;i<n;i++){
		if(i<freq[1] and a[i]!=1){
			swap[a[i]][1]++;
		}
		else if(i>=freq[1] and i<freq[2]+freq[1] and a[i]!=2){
			swap[a[i]][2]++;
		}
		else if(i>=freq[1]+freq[2] and a[i]!=3){
			swap[a[i]][3]++;
		}
	}
	int ans=0, val=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			ans+=min(swap[i][j], swap[j][i]);
			val+=max(swap[i][j], swap[j][i])-min(swap[i][j], swap[j][i]);
		}
	}
	ans/=2;
	val/=2;
	ans+=val>0?val/2+1: 0;
	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
