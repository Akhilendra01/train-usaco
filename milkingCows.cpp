
/*
ID: akhilen1
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

typedef pair<int, int> pii;
#define f first
#define s second

void solve(){
	int n;
	cin>>n;

	vector<pii> v(n);
	for(int i=0;i<n;i++)cin>>v[i].f>>v[i].s;

	sort(v.begin(), v.end());

	int i=0, cur=0, mx=0;
	while(i<n){
		int j=i+1;
		int st=v[i].f, en=v[i].s;
		while(j<n and en>=v[j].f)j++, en=max(en, v[j-1].s);
		mx=max(mx, en-st);
		i=j;
	}

	int mx1=0;
	int en=v[0].s;
	for(int i=1;i<n;i++){
		mx1=max(mx1, v[i].f-en);
		en=max(en, v[i].s);
	}
	cout<<mx<<" "<<mx1<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
