/*
ID: akhilen1
TASK: milk3
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> cap(3);
int vis[21][21][21];

vector<int> val;

void f(vector<int> v){
	if(vis[v[0]][v[1]][v[2]])return;

	vis[v[0]][v[1]][v[2]]=1;

	if(v[0]==0)val.push_back(v[2]);

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i!=j and v[i]!=0 and v[j]<cap[j]){
				vector<int> u=v;
				u[i]=max((int)0, v[i]-cap[j]+v[j]);
				u[j]=min(cap[j], v[i]+v[j]);
				f(u);
			}
		}
	}
}

void solve(){
	cin>>cap[0]>>cap[1]>>cap[2];
	f({0, 0, cap[2]});
	sort(val.begin(), val.end());

	for(int i=0;i<val.size();i++){
		cout<<val[i];
		if(i!=val.size()-1)cout<<" ";
	}
	cout<<"\n";
}
int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
