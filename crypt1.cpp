
/*
ID: akhilen1
TASK: crypt1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

bool ok(int num, vector<int>& v){
	int n=v.size();

	while(num>0){
		int d=num%10;
		num/=10;
		bool flag=0;
		for(int i=0;i<n;i++)if(v[i]==d)flag=1;
		if(!flag)return false;
	}
	return true;
}


void solve(){
	int n; cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];


	int ans=0;
	for(int ai=0;ai<n;ai++)
	for(int bi=0;bi<n;bi++)
	for(int ci=0;ci<n;ci++)
	for(int di=0;di<n;di++)
	for(int ei=0;ei<n;ei++)
	{
		int a=v[ai], b=v[bi], c=v[ci], d=v[di], e=v[ei];

		int abc=a*100+b*10+c;
		int de=d*10+e;

		int p1=abc*e, p2=abc*d;
		int res=p2*10+p1;

		if(p1>=100 and p1<1000 and p2>=100 and p2<1000 and res>=1000 and res<10000)
		if(ok(abc, v) and ok(de, v) and ok(p1, v) and ok(p2, v) and ok(res, v)){
			ans++;
		}
	}
	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
