
/*
ID: akhilen1
TASK: wormhole
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, ans;
int x[20], y[20], nxt[20], paired[20], part[20];

bool check(){
	for(int s=1;s<=n;s++){
		int cur=s;
		for(int i=1;i<=n;i++)cur=part[nxt[cur]];
		if(cur)return true;
	}
	return false;
}

void dfs(){
	int f=1;
	while(f<=n and paired[f])f++;

	if(f==n+1){
		if(check())ans++;
		return;
	}

	for(int s=f+1;s<=n;s++){
		if(!paired[s]){
			paired[f]=paired[s]=1;
			part[f]=s, part[s]=f;
			dfs();
			paired[f]=paired[s]=0;
			part[f]=part[s]=0;

		}
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];

	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i!=j and y[i]==y[j] and x[i]<=x[j] and (!nxt[i] or x[j]<=x[nxt[i]]))nxt[i]=j;
	}

	dfs();
	cout<<ans<<"\n";
}

int32_t main(){

	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
