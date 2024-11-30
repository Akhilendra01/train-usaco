/*
ID: akhilen1
TASK: range
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int n;
int pr[251][251]; //for storing 2d prefix
vector<string> a;


void computePrefix(){
	for(int i{1};i<=n;i++){
		for(int j{1};j<=n;j++){
			pr[i][j]=pr[i-1][j]+pr[i][j-1]-pr[i-1][j-1]+(a[i-1][j-1]-'0');
		}
	}
}

int queryPrefix(int c, int d, int m){
	int a{c-m+1}, b{d-m+1};
	if(a<1 or b<1){
		return 0;
	}
	return pr[c][d]-pr[a-1][d]-pr[c][b-1]+pr[a-1][b-1];
}

void solve(){
	cin>>n;
	a.resize(n);
	for(int i{};i<n;i++)cin>>a[i];

	computePrefix();
	
	for(int dim{2};dim<=n;dim++){
		int ans{};
		for(int i{dim};i<=n;i++)
		for(int j{dim};j<=n;j++){
			ans+=(queryPrefix(i, j, dim)==dim*dim);
		}
		if(ans){
			cout<<dim<<" "<<ans<<"\n";
		}
	}
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
