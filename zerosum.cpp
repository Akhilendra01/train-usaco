/*
ID: akhilen1
TASK: zerosum
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int N;
vector<string>ans;
int evaluate(string& s){
	int res{0}, cur{};
	bool pos{true};

	for(int i{};i<s.size();i+=1){
		if(s[i]=='-'){
			res+=pos?cur:-cur;
			cur=0;
			pos=false;
		}else if(s[i]=='+'){
			res+=pos?cur:-cur;
			cur=0;
			pos=true;
		}else if(s[i]==' '){
			continue;
		}else{
			cur=cur*10+(s[i]-'0');
		}
	}
	res+=pos?cur:-cur;
	return res;
}

void dfs(int n, string s){
	if(n==N+1){
		if(evaluate(s)==0){
			ans.push_back(s);
		}
		return;
	}

	dfs(n+1, s+"+"+to_string(n));
	dfs(n+1, s+"-"+to_string(n));
	dfs(n+1, s+" "+to_string(n));
}

void solve(){
	cin>>N;
	dfs(2, "1");
	sort(ans.begin(), ans.end());
	for(string s: ans)cout<<s<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
