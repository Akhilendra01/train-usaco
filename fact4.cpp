/*
ID: akhilen1
TASK: fact4
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
	int n;
	cin>>n;

	vector<int> v(n+1);
	iota(v.begin(), v.end(), 0);

	int c2{}, c5{};

	for(int i{1};i<=n;i++){
		while(v[i]%2==0){
			c2++;
			v[i]/=2;
		}
		while(v[i]%5==0){
			c5++;
			v[i]/=5;
		}
	}

	int ans{1};
	for(int i{1};i<=n;i++){
		ans=(ans*v[i])%10;
	}

	c2-=c5;
	while(c2--){
		ans=(ans*2)%10;
	}

	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
