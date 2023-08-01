/*
ID: akhilen1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int32_t main(){

	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	vector<string> v(n);
	map<string, int> mp;
	for(int i=0;i<n;i++){
		cin>>v[i];
		mp.insert({v[i], 0});
	}

	for(int i=0;i<n;i++){
		string s; cin>>s;
		int tot, people;
		cin>>tot>>people;

		int money=(tot/(people ?people: 1));
		int left=tot-money*people;
		mp[s]-=tot;
		mp[s]+=left;
		for(int j=0;j<people;j++){
			string q; cin>>q;
			mp[q]+=money;
		}
	}

	for(string name: v)cout<<name<<" "<<mp[name]<<"\n";
	
	return 0;
}
