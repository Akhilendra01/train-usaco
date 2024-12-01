/*
ID: akhilen1
TASK: fence9
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int inf{(int)1e18};

class Line{
public:
	double minv, c, x_int;
	Line(double minv, double c, double x_int): minv(minv), c(c), x_int(x_int){}

	double getX(double y){
		if(c==inf){
			return x_int;
		}
		return (y-c)*minv;
	}
};



int n, m, p;

void solve(){
	cin>>n>>m>>p;

	Line *l1{new Line(n*1.0/m, 0.0, 0.0)};

	Line *l2{new Line((n-p)*1.0/m, n==p?inf: -m*p*1.0/(n-p), p) };

	int ans{};
	for(int i{1};i<m;i++){
		double x1{ l1->getX(i) +1e-6};
		double x2{ l2->getX(i) -1e-6};

		x1=floor(x1)+1;
		x2=ceil(x2)-1;
		if(x1<=x2)ans+=x2-x1+1;
	}

	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
