/*
ID: akhilen1
TASK: cowtour
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

const double inf{1e10};

int n;
double x[150], y[150], d[150][150];

double dist(int i, int j){
	return sqrtl( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
}

void solve(){
	cin>>n;
	for(int i{};i<n;i++)cin>>x[i]>>y[i];

	for(int i{};i<n;i++){
		string s;
		cin>>s;

		for(int j{};j<n;j++){
			if(s[j]=='1'){
				d[i][j]=dist(i, j);
			}else{
				d[i][j]=inf;
			}
			if(i==j){
				d[i][j]=0;
			}
		}
	}

	for(int k{};k<n;k++)
	for(int i{};i<n;i++)
	for(int j{};j<n;j++)
		d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
	
	double ans{inf};
	vector<double> mxdist(n);

	for(int i{};i<n;i++){
		mxdist[i]=0;
		for(int j{};j<n;j++){
			if(d[i][j]==inf)continue;
			mxdist[i]=max(d[i][j], mxdist[i]);
		}
		for(int j{};j<i;j++){
			if(d[i][j]!=inf)continue;
			ans=min( ans, mxdist[i]+dist(i, j) +mxdist[j] );
		}
	}

	for(int i{};i<n;i++){
		ans=max(ans, mxdist[i]);
	}

	cout<<fixed<<setprecision(6)<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
