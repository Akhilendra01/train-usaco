/*
ID: akhilen1
TASK: fracdec
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
	int a, b;
	cin>>a>>b;

	map<int, int> last;
	map<int, int> trail;

	int n{a%b}, I{a/b};

	string ans{to_string(I)+"."};

	if(n==0){
		ans+='0';
		cout<<ans<<"\n";
		return;
	}

	int idx{(int)ans.size()};

	while(last.find(n)==last.end() and n){
		last[n]=idx;
		int x{n}, c{};
		while(x%10==0){
			c++;
			x/=10;
			last[x]=idx;
			trail[x]=c;
		}

		idx++;

		if(n<b)n*=10;
		while(n<b){
			n*=10;
			ans+='0';
			idx++;
		}

		ans+=to_string(n/b);
		n%=b;
	}

	bool ok{false};

	while(trail[n]--)ans+='0';

	int c{};

	for(int i{};i<ans.size();i++){
		if(c%76==0 and i>0){
			cout<<"\n";
		}
		if(i==last[n] and last[n]){
			cout<<"(";
			ok=true;
			c++;
		}
		cout<<ans[i];
		c++;
	}
	if(ok){
		if(c%76==0)cout<<"\n";
		cout<<")";
	}
	c++;
	cout<<"\n";
}	

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
