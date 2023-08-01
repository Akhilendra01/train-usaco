
/*
ID: akhilen1
TASK: palsquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

string val="0123456789ABCDEFGHIJ";

string convert(int num, int base){
	string s="";
	while(num){
		s+=val[num%base];
		num/=base;
	}
	reverse(s.begin(), s.end());
	return s;
}

bool ispalin(string s){
	string a=s;
	reverse(a.begin(), a.end());
	return a==s;
}

void solve(){
	int b;
	cin>>b;

	for(int i=1;i<=300;i++){
		string a=convert(i, b);
		string c=convert(i*i, b);	
		if(ispalin(c))cout<<a<<" "<<c<<"\n";
	}

}	

int32_t main(){

	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
