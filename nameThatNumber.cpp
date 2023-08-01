
/*
ID: akhilen1
TASK: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

vector<vector<char>> dict{
	{'A', 'B', 'C'},
	{'D', 'E', 'F'},
	{'G', 'H', 'I'},
	{'J', 'K', 'L'},
	{'M', 'N', 'O'},
	{'P', 'R', 'S'},
	{'T', 'U', 'V'},
	{'W', 'X', 'Y'},
};

set<string>st;
bool none=true;
void f(string s, int idx, string res){
	if(idx==s.size()){
		if(st.find(res)!=st.end()){
			cout<<res<<"\n";
			none=false;
		}
		return;
	}

	int val=s[idx]-'0';
	for(int i=0;i<3;i++)f(s, idx+1, res+dict[val-2][i]);
}

void solve(){
	string s;
	cin>>s;

	ifstream fin("dict.txt");
	while(!fin.eof()){
		string x;
		fin>>x;
		st.insert(x);
	}
	fin.close();
	f(s, 0, "");
	if(none)cout<<"NONE\n";
}	

int32_t main(){

	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();	
	
	return 0;
}
