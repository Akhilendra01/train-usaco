#include<bits/stdc++.h>
using namespace std;

#define int               long long int
#define double            long double
#define vi                vector<int>
#define pii               pair<int, int>
#define inp0(a, n)        for(int i{0};i<n;i++)cin>>a[i]
#define inp1(a, n)        for(int i{1};i<=n;i++)cin>>a[i]
#define out0(a, n)        for(int i{0};i<n;i++)cout<<a[i]<<" "; cout<<"\n"
#define out1(a, n)        for(int i=1;i<=n;i++)cout<<a[i]<<" "; cout<<"\n"
#define pb                push_back
#define ff                first
#define ss                second

const int inf{(int)1e18};
const int mod{(int)1e9+7};
const double PI{(double)acos(-1)};
const bool testcases{false};

typedef long long ll;

string longestEvenWord(string sentence){
  vector<string>words;

  stringstream ss(sentence);

  string w;
  while(getline(ss, w, ' ')){
    if(((int)w.size())%2==0){
      words.push_back(w);
    }
  }

  int mx=0;
  for(string word: words){
    mx=max(mx, (int)word.size());
  }

  for(string word: words){
    if((int)word.size()==mx){
      return word;
    }
  }

  return "00";
}

void solve(){
    string s;
    getline(cin, s);
    cout<<longestEvenWord(s);
}

int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t{1};
  if(testcases)cin>>t;
  while(t--){
    solve();
  }
  
  return 0;
}