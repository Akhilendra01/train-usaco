#include<bits/stdc++.h>
using namespace std;

#define int               long long int
#define double            long double
#define vi                vector<int>
#define pii               pair<int, int>
#define inp0(a, n)        for(int i=0;i<n;i++)cin>>a[i]
#define inp1(a, n)        for(int i=1;i<=n;i++)cin>>a[i]
#define out0(a, n)        for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<"\n"
#define out1(a, n)        for(int i=1;i<=n;i++)cout<<a[i]<<" "; cout<<"\n"
#define pb                push_back
#define ff                first
#define ss                second

const int inf=1e18;
const int mod=1e9+7;
const double PI=(double)acos(-1);
const bool testcases=0;

void solve(){
  int n;
  cin>>n;

  vector<pair<int, int>> v(n);
  for(int i=0;i<n;i++){
  	cin>>v[i].first>>v[i].second;
  }

  sort(v.begin(), v.end());

  vector<pair<int, int>> u(n);
  for(int i=0;i<n;i++){
    cin>>u[i].first>>u[i].second;
  }

  sort(u.begin(), u.end());

  int i=0, j=0, ans=0, last=0;
  while(i<n and j<n){
    int c=0;
    while(v[i].first<u[j].first and v[i].second<u[j].second){
      i++;
      c++;
    }
    j++;
    // ans+=c*last+c;
    // last=c-1;
  }
  cout<<ans<<"\n";
}
int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t=1;
  if(testcases)cin>>t;
  while(t--){
    solve();
  }
  
  return 0;
}