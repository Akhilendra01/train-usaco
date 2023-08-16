/*
ID: akhilen1
TASK: maze1
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int


int n, m;
string gr[500];
int ans[500][500];

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

void dfs(int x, int y, int d){
	if(d>=ans[x][y])return;
	ans[x][y]=d;

	for(int i{};i<4;i++){
		int xx{x+dx[i]}, yy{y+dy[i]};
		if(xx<0 or yy<0 or xx>n or yy>m)continue;
		if(gr[xx][yy]=='-' or gr[xx][yy]=='|')continue;
		xx+=dx[i];
		yy+=dy[i];
		if(xx<0 or yy<0 or xx>n or yy>m)continue;
		if(gr[xx][yy]=='-' or gr[xx][yy]=='|')continue;
		dfs(xx, yy, d+1);
	}
}

void solve(){
	cin>>m>>n;
	n*=2, m*=2;

	getline(cin, gr[0]);
	for(int i{};i<=n;i++){
		getline(cin, gr[i]);
	}

	for(int i{};i<=n;i++)
	for(int j{};j<=m;j++)ans[i][j]=(int)1e10;

	for(int i{};i<=n;i++){
		if(gr[i][0]==' '){
			dfs(i, 1, 1);
		}
		if(gr[i][m]==' '){
			dfs(i, m-1, 1);
		}
	}

	for(int j={};j<=m;j++){
		if(gr[0][j]==' '){
			dfs(1, j, 1);
		
}}
		if(gr[n][j]==' '){
			dfs(n-1, j, 1);
		}
	}

	int mx{};
	for(int i{1};i<=n;i+=2)
	for(int j{1};j<=m;j+=2)mx=max(mx, ans[i][j]);

	cout<<mx<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
