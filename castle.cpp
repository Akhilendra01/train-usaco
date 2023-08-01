/*
ID: akhilen1
TASK: castle
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int


int n, m;

int a[50][50];
int cc[50][50];
int vis[50][50];
map<int, int> sz;
int c, cnt, mx;

void dfs(int i, int j){
	if(i==-1 or j==-1 or i==n or j==m)return;
	if(vis[i][j])return;
	vis[i][j]=1;
	int wall=a[i][j];
	cc[i][j]=c;
	cnt++;

	if((wall&1)==0){
		dfs(i, j-1);
	}
	
	wall>>=1;
	if((wall&1)==0){
		dfs(i-1, j);
	}	
	
	wall>>=1;
	if((wall&1)==0){
		dfs(i, j+1);
	}

	wall>>=1;
	if((wall&1)==0){
		dfs(i+1, j);
	}
}


bool ok(int i, int j, int ii, int jj){
	if(i==ii and j==jj)return true;
	if(j<jj)return false;
	if(i>ii)return false;
	return true;
}

void solve(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>a[i][j];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]){
				c++;
				cnt=0;
				dfs(i, j);
				sz[c]=cnt;
				mx=max(mx, cnt);
			}
		}
	}
	cout<<c<<"\n"<<mx<<"\n";

	int dx[]={0, -1, 0, 1};
	int dy[]={-1, 0, 1, 0};
	char dir[]={'W', 'N', 'E' ,'S'};
	int x=0, y=0, mx=0;
	char d='S';

	for(int j=0;j<m;j++)
	for(int i=n-1;i>=0;i--){
		for(int k=1;k<=2;k++){
			int ii=i+dx[k], jj=j+dy[k];
			if(ii<0 or ii>=n or jj<0 or jj>=m)continue;
			int s=sz[cc[i][j]];
			if(cc[i][j]!=cc[ii][jj])s+=sz[cc[ii][jj]];
			if(s>mx){
				mx=s;
				x=i;
				y=j;
				d=dir[k];
			}
		}
	}
	cout<<mx<<"\n";
	cout<<x+1<<" "<<y+1<<" "<<d<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
