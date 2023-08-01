/*
ID: akhilen1
TASK: hamming
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n, b, d, taken[1<<8];

int dist(int x, int y){
	int res{};
	for(int i=0;i<b;i++){
		int b1=((x>>i)&1);
		int b2=((y>>i)&1);
		res+=(b1!=b2);
	}
	return res;
}

bool f(vector<int>& v){
	if(v.size()==n){
		for(int i=0;i<n;i++){
			cout<<v[i];
			if(i==n-1){
				cout<<"\n";
			}else{
				if((i+1)%10==0){
					cout<<"\n";
				}else{
					cout<<" ";
				}
			}
		}
		return true;
	}

	for(int i=1;i<(1<<b);i++){
		if(taken[i])continue;
		bool ok=1;
		for(int x: v){
			if(dist(x, i)<d){
				ok=0;
				break;
			}
		}
		if(ok){
			v.push_back(i);
			taken[i]=1;
			bool res=f(v);
			if(res)return true;
			v.pop_back();
			taken[i]=0;
		}
	}
	return false;
}

void solve(){
	cin>>n>>b>>d;
	vector<int> v{0};
	taken[0]=1;
	f(v);
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
