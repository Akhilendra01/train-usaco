/*
ID: akhilen1
TASK: lamps
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n, cc, x;
vector<int> on, off;
set<vector<int>> st;

bool ok(vector<int> lamps){
	for(int x: on)if(lamps[x]==0)return false;
	for(int x: off)if(lamps[x]==1)return false;
	return true;
}

void f(vector<int> lamps, int count, bool a, bool b, bool c, bool d){
	if(count>cc)return;
	if((cc-count)%2==0){
		if(ok(lamps)){
			st.insert(lamps);
		}
	}

	if(!a){
		for(int i=1;i<=n;i+=1)lamps[i]=1-lamps[i];
		f(lamps, count+1, 1, b, c, d);
		for(int i=1;i<=n;i+=1)lamps[i]=1-lamps[i];
	}
	
	if(!b){
		for(int i=1;i<=n;i+=2)lamps[i]=1-lamps[i];
		f(lamps, count+1, a, 1, c, d);
		for(int i=1;i<=n;i+=2)lamps[i]=1-lamps[i];	
	}

	if(!c){
		for(int i=2;i<=n;i+=2)lamps[i]=1-lamps[i];
		f(lamps, count+1, a, b, 1, d);
		for(int i=2;i<=n;i+=2)lamps[i]=1-lamps[i];	
	}
	
	if(!d){
		for(int i=1;i<=n;i+=3)lamps[i]=1-lamps[i];
		f(lamps, count+1, a, b, c, 1);
		for(int i=1;i<=n;i+=3)lamps[i]=1-lamps[i];	
	}

}

void solve(){
	cin>>n>>cc;

	cin>>x;
	while(x!=-1){
		on.push_back(x);
		cin>>x;
	}

	cin>>x;
	while(x!=-1){
		off.push_back(x);
		cin>>x;
	}

	vector<int> lamps(n+1, 1);

	f(lamps, 0, 0, 0, 0, 0);
	if(st.empty()){
		cout<<"IMPOSSIBLE\n";
		return;
	}

	for(auto& v: st){
		for(int i=1;i<=n;i++)cout<<v[i];
		cout<<"\n";
	}

}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
