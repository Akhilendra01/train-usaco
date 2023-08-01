/*
ID: akhilen1
TASK: sprime
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool isprime(int n){
	if(n==2)return true;
	if(n==1 or n%2==0)return false;
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0)return false;
	}
	return true;
}

int n; 
void f(int idx, int num, int z){
	if(idx==n){
		if(isprime(num))cout<<num<<"\n";
		return;
	}
	int lb=(z==1);
	for(int i=lb;i<=9;i++){
		if(isprime(num*10+i))f(idx+1, num*10+i, 0);
	}
}

void solve(){
	cin>>n;
	f(0, 0, 1);
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
