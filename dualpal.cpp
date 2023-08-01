
/*
ID: akhilen1
TASK: dualpal
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
	int n, s;

	cin>>n>>s;

	map<int, int>mp; 

	for(int i=s+1;i<=50000;i++){
		for(int base=2;base<=10;base++){
			string x=convert(i, base);
			if(ispalin(x))mp[i]++;
		}
	}

	vector<int>v;
	for(int i=s+1;i<=50000;i++)if(mp[i]>1)v.push_back(i);

	for(int i=0;i<n;i++)cout<<v[i]<<"\n";
}	

int32_t main(){

	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
