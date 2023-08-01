
/*
ID: akhilen1
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
	int n;
	cin>>n;
	string s; cin>>s;

	int mx=0, cur=0;

	for(int i=0;i<n-1;i++){
		int j=i;
		cur=0;
		char last=s[i];
		while(s[j]==last or s[j]=='w' or last=='w'){
			if(last=='w')last=s[j];
			cur++;
			j=(j-1+n)%n;
			if(j==i)break;
		}

		j=i+1;
		last=s[i+1];
		while(s[j]==last or s[j]=='w' or last=='w'){
			if(last=='w')last=s[j];
			cur++;
			j=(j+1)%n;
			if(j==i+1)break;
		}
		mx=max(mx, cur);
	}
	mx=min(mx, n);
	cout<<mx<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
