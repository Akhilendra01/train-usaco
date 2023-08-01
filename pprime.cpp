/*
ID: akhilen1
TASK: pprime
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long int


int rev(int n){
	int rev=0;
	while(n){
		rev=rev*10+n%10;
		n/=10;
	}
	return rev;
}

int concat(int x, int y){
	while(y){
		x=x*10+y%10;
		y/=10;
	}
	return x;
}

bool isprime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}

void solve(){
	int a, b;
	cin>>a>>b;
	vector<int> v;
	for(int d1=0;d1<=9;d1++)
	for(int d2=0;d2<=9;d2++)
	for(int d3=0;d3<=9;d3++)
	for(int d4=0;d4<=9;d4++)
	for(int d5=0;d5<=9;d5++){
		int num=d5+d4*10+d3*100+d2*1000+d1*10000;
		int x=concat(num/10, num);
		if(x>=a and x<=b and isprime(x))v.push_back(x);
		x=concat(num, num);
		if(x>=a and x<=b and isprime(x))v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int x: v)cout<<x<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
