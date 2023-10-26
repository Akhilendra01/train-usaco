/*
ID: akhilen1
TASK: ratios
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int

const int inf{(int)1e9};

void solve(){

	int g[3], m[3][3];
	for(int i{};i<3;i++)cin>>g[i];

	for(int i{};i<3;i++){
		for(int j{};j<3;j++)cin>>m[i][j];
	}


	int ans{inf}, a, b, c, val;

	int x[3];
	for(x[0]=0;x[0]<=100;x[0]++)
	for(x[1]=0;x[1]<=100;x[1]++)
	for(x[2]=0;x[2]<=100;x[2]++){
		if(x[1]==0 and x[2]==0 and x[3]==0)continue;
		vector<int> y(3);
		for(int i{};i<3;i++){
			for(int j{};j<3;j++)y[j]+=x[i]*m[i][j];
		}
		bool ok{true};
		for(int i{};i<3;i++){
			if(y[i]==0){
				if(g[i])ok=false;
			}
			else if(g[i]==0){
				if(y[i])ok=false;
			}
			else if(y[i]%g[i]){
				ok=false;
			}
		}

		if(ok and ans>x[0]+x[1]+x[2] and y[0]*g[1]==y[1]*g[0] and y[1]*g[2]==y[2]*g[1]){
			ans=x[0]+x[1]+x[2];
			a=x[0], b=x[1], c=x[2];
			val=g[0]==0?0:y[0]/g[0];
		}
	}
	if(ans==inf){
		cout<<"NONE\n";
		return;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<val<<"\n"; 
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
