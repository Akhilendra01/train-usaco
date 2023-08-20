/*
ID: akhilen1
TASK: contact
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int f(string s){
	int x{1}, res{};
	reverse(s.begin(), s.end());
	for(char c: s){
		res+=x*(c-'0');
		x*=2;
	}
	return res;
}

void solve(){
	int a, b, n;
	string s;
	cin>>a>>b>>n;

	string w;
	while(getline(cin, w)){
		s+=w;
	}

	map<string, int> mp;

	int i{}, j{}, m{(int)s.size()};
	while(i<m){
		int l{j-i+1};
		while(j<m and l<=b){
			if(l>=a){
				mp[s.substr(i, l)]++;
			}
			++l;
			++j;
		}
		++i;
		j=i;
	}
	
	map<int, vector<string>> ls;

	set<int> pq;

	for(auto [str, freq]: mp){
		ls[freq].push_back(str);
		pq.insert(freq);
		if(pq.size()>n){
			pq.erase(*pq.begin());
		}
	}

	vector<int> v;
	for(int x: pq)v.push_back(x);

	reverse(v.begin(), v.end());

	for(int freq: v){
		cout<<freq<<"\n";
		sort(ls[freq].begin(), ls[freq].end(), [&](string a, string b)->bool{
			if(a.size()<b.size())return true;
			if(a.size()>b.size())return false;
			return f(a)<f(b);
		});
		int c{};
		for(int i{};i<ls[freq].size();i++){
			if(c%6==0 and c)cout<<"\n";
			cout<<ls[freq][i];
			c++;
			if(i==ls[freq].size()-1)break;
			if(c%6!=0 or c==0)cout<<" ";
		}
		cout<<"\n";
	}
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
