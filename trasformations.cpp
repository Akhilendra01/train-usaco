/*
ID: akhilen1
TASK: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<vector<char>> rotate90clk(vector<vector<char>>&a){
	int n=a.size();
	vector<vector<char>>c(n, vector<char>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[j][i]=a[i][j];
		}
	}
	for(int i=0;i<n;i++)reverse(c[i].begin(), c[i].end());
	return c;
}


vector<vector<char>> reflecthz(vector<vector<char>>&a){
	int n=a.size();
	vector<vector<char>>c=a;
	for(int i=0;i<n;i++)reverse(c[i].begin(), c[i].end());
	return c;
}

bool comp(vector<vector<char>>&b, vector<vector<char>>&c){
	int n=b.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i][j]!=b[i][j])return false;
		}
	}
	return true;
}

int f1(vector<vector<char>>&a, vector<vector<char>>&b){
	int n=a.size();

	vector<vector<char>>c=rotate90clk(a);
	bool ok=comp(b, c);
	if(ok)return 1;
	
	c=rotate90clk(c);
	ok=comp(b, c);
	if(ok)return 2;

	c=rotate90clk(c);
	ok=comp(b, c);
	if(ok)return 3;

	c=reflecthz(a);
	ok=comp(b, c);
	if(ok)return 4;


	c=rotate90clk(c);
	ok=comp(b, c);
	if(ok)return 5;

	c=rotate90clk(c);
	ok=comp(b, c);
	if(ok)return 5;

	c=rotate90clk(c);
	ok=comp(b, c);
	if(ok)return 5;

	ok=comp(a, b);
	if(ok)return 6;

	return 7;

	return 0;
} 

void solve(){
	int n; cin>>n;
	vector<vector<char>> a(n, vector<char>(n));
	vector<vector<char>> b(n, vector<char>(n));

	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>b[i][j];

	cout<<f1(a, b)<<"\n";
}

int32_t main(){

	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
