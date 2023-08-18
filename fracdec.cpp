/*
ID: akhilen1
TASK: test
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

typedef pair<int, pair<int, int>> pp;

void solve(){
    int k,n; cin>>k>>n;

    int mx=-1,mn=INT_MAX;

    int a[k][n];

	for(int i=0;i<k;i++){
	    for(int j=0;j<n;j++){
	        cin>>a[i][j];
	    }
	}

	priority_queue<pp, vector<pp>, greater<pp>>pq;
	for(int i=0;i<k;i++){
	    pq.push({a[i][0], {i,0}});
	    mx=max(mx, a[i][0]);
	    mn=min(mn, a[i][0]);
	} 
	
	int ans= mx-mn;
	int lf=mn, rt=mx;
	
	while(!pq.empty()){
	    pair<int,pair<int,int>>p= pq.top();
	    pq.pop();
	    
	    mn=p.first;
	    if(mx-mn<ans){
	        ans=mx-mn;
	        lf=mn, rt=mx;
	    }
	    int row= p.second.first;
	    int col= p.second.second;
	    
	    if(col+1<n){
	        pq.push({a[row][col+1],{row,col+1}});
	        if(a[row][col+1]>mx){
	            mx=a[row][col+1];
	        }
	    }
	    else{
	        break;
	    }   
	}
    cout<<lf<<" "<<rt<<endl;
}

int32_t main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
