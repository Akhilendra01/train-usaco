/*
ID: akhilen1
TASK: spin
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N{5};

int speed[N], num[N], stangle[N][N], ext[N][N];
void solve(){
	
	for(int i{};i<N;i++){
		cin>>speed[i]>>num[i];
		for(int j{};j<num[i];j++){
			cin>>stangle[i][j]>>ext[i][j];
		}
	}

	int p[360];

	for(int i{};i<360;i++){
		memset(p, 0, sizeof(p));
		for(int j{};j<N;j++){
			for(int k{};k<num[j];k++){
				int st{ speed[j]*i+stangle[j][k] };
				int en{ st+ext[j][k] };
				for(int m{st};m<=en;m++)p[m%360]++;
			}
		}
		for(int j{};j<360;j++){
			if(p[j]==5){
				cout<<i<<"\n";
				return;
			}
		}
	}
	cout<<"none\n";
}
	
int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
