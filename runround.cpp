/*
ID: akhilen1
TASK: runround
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int



bool runaround(int n){
	vector<int> dig;
	while(n){
		dig.push_back(n%10);
		n/=10;
	}

	reverse(dig.begin(), dig.end());

	vector<int> freq(10);
	for(int i=0;i<dig.size();i++){
		if(dig[i]==0)return false;
		freq[dig[i]]++;
		if(freq[dig[i]]>1){
			return false;
		}
	}

	int cur{}, ncur;
	vector<int> cnt(10);
	for(int i=0;i<dig.size();i++){
		ncur=(cur+dig[cur])%dig.size();
		cnt[dig[cur]]++; 
		if(cnt[dig[ncur]] and ncur!=0)return false;
		cur=ncur;
	}

	return true;
}

void solve(){
	int n;
	cin>>n;
	++n;
	while(!runaround(n))++n;
	cout<<n<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
