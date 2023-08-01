
/*
ID: akhilen1
TASK: ariprog
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

// #define int long long int

const int mx=251;

int n, m;
bool bs[2*mx*mx], none=true;

bool check(int s, int d){
	for(int i=0;i<n;i++){
		if(s+i*d<=2*mx*mx-1 and !bs[s+i*d])return false;
	}
	return true;
}

void solve(){
	cin>>n>>m;
	vector<pair<int, int>> v;
	for(int p=0;p<=m;p++)
	for(int q=0;q<=m;q++)bs[p*p+q*q]=1;
	
	for(int s=0;s<=2*m*m;s++)
	for(int d=1;d<=(2*m*m-s)/(n-1);d++){
		if(check(s, d)){
			v.push_back({d, s});
			none=false;
		}
	}	
	
	if(none)cout<<"NONE\n";
	sort(v.begin(), v.end());
	for(auto [d, s]: v)cout<<s<<" "<<d<<"\n";
}

int32_t main(){

	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
