
/*
ID: akhilen1
PROG: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int32_t main(){

	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin>>a>>b;

    int v1=1, v2=1;

    for(char c: a){
    	v1=(v1*(c-'A'+1))%47;
    }
    for(char c: b){
    	v2=(v2*(c-'A'+1))%47;
    }
		
	if(v1==v2)cout<<"GO\n";
	else cout<<"STAY\n";
	
	return 0;
}
