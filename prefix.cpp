/*
ID: akhilen1
TASK: prefix
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

string s;
unordered_set<string>st;

void solve(){
	cin>>s;
	while(s!="."){
		st.insert(s);
		cin>>s;
	}
	string w;
	s="";
	while(getline(cin, w)){
		s+=w;
	}

	int n{(int)s.size()};
	vector<bool> dp(n+1, 0);
	dp[0]=1;
	for(int i{1};i<=n;i++){
		for(int j{i};j<=min(n, i+10);j++){
			string w{s.substr(i-1, j-i+1)};
			if(st.find(w)!=st.end()){
				dp[j]=(dp[j]||dp[i-1]);
			}
		}	
	}

	for(int i=n;i>=0;i--){
		if(dp[i]){
			cout<<i<<"\n";
			break;
		}
	}

}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
