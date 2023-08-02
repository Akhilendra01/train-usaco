/*
ID: akhilen1
TASK: preface
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> values {1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string> literal {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

string convert(int num){
	string res="";
	for(int i=0;i<values.size();i++){
		while(num>=values[i]){
			num-=values[i];
			res+=literal[i];
		}
	}
	return res;
}

void solve(){
	int N;
	cin>>N;

	map<char, int> idx;
	idx['I']=0;
	idx['V']=1;
	idx['X']=2;
	idx['L']=3;
	idx['C']=4;
	idx['D']=5;
	idx['M']=6;
	

	map<int, char> key;
	key[0]='I';
	key[1]='V';
	key[2]='X';
	key[3]='L';
	key[4]='C';
	key[5]='D';
	key[6]='M';

	vector<int> freq(7, 0);
	
	for(int n=1;n<=N;n++){
		string res=convert(n);
		for(char c: res)freq[idx[c]]++;
	}

	for(int i=0;i<7;i++){
		if(freq[i]){
			cout<<key[i]<<" "<<freq[i]<<"\n";
		}
	}
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
