/*
ID: akhilen1
TASK: ttwo
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int n{10};

char mat[n][n];

int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

class state{
public:
	int x, y, dir;
	
	state(int x, int y){
		this->x=x;
		this->y=y;
		dir=0;
	}
	
	void move(){
		int x1{x+dx[dir]}, y1{y+dy[dir]};
		if(x1<0 or y1<0 or x1>=n or y1>=n or mat[x1][y1]=='*'){
			dir=(dir+1)%4;
		}else{
			x=x1;
			y=y1;
		}
	}
};

void solve(){
	state *f, *c;

	for(int i{};i<n;i+=1)
	for(int j{};j<n;j+=1){
		cin>>mat[i][j];
		if(mat[i][j]=='F'){
			f=new state(i, j);
		}

		if(mat[i][j]=='C'){
			c=new state(i, j);
		}
	}


	int ans{};
	while(ans<2e5 and !(f->x==c->x and f->y==c->y)){
		f->move();
		c->move();
		ans++;
	}
	if(ans>=2e5)ans=0;
	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
