/*
ID: akhilen1
TASK: fence6
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

class DSU{
private:
	int n, *par, *rank;
public:
	DSU(int n){
		this->n=n;
		par=(int*)malloc(sizeof(int)*(n+1));
		rank=(int*)malloc(sizeof(int)*(n+1));
		memset(rank, 0, sizeof(rank));
		iota(par, par+n+1, 0);
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void merge(int a, int b){
		a=find(a), b=find(b);
		if(a!=b){
			if(rank[a]<rank[b])swap(a, b);
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
};

class Segment{
public:
	int sid, len, n1, n2;
	set<int> v[2];
	Segment(int sid, int len, int n1, int n2):
	sid{sid}, len{len}, n1{n1}, n2{n2} {}

	void input(){
		for(int i{};i<n1;i++){
			int x; cin>>x;
			v[0].insert(x);
		}
		for(int i{};i<n2;i++){
			int x; cin>>x;
			v[1].insert(x);
		}
	}
};


int n;
vector<Segment*> a;
map<int, int> idx;
vector<set<pair<int, int>>> gr;


set<int> st;
vector<int> cur;
map<int, int> vis;
map<pair<int, int>, int> edwt;

int ans{INT_MAX};
void dfs(int node, int par){
	vis[node]=1;
	st.insert(node);
	cur.push_back(node);

	for(auto[child, wt]: gr[node]){
		if(child==par)continue;
		if(vis[child]==0){
			dfs(child, node);
		}
		else if(st.find(child)!=st.end()){
			int idx{(int)cur.size()-1}, curlen{};
			while(cur[idx]!=child)idx--;
			int z{};
			while(idx<cur.size()-1){
				if(edwt[{cur[idx], cur[idx+1]}]){
					z++;
				}
				curlen+=edwt[{cur[idx], cur[++idx]}];
			}
			curlen+=wt;
			if(wt)z++;
			if(curlen and z>1)ans=min(ans, curlen);
		}
	}
	vis[node]=0;
	cur.pop_back();
	st.erase(node);
}


void solve(){
	cin>>n;
	a.resize(n);
	for(int i{};i<n;i++){
		int sid, len, n1, n2;
		cin>>sid>>len>>n1>>n2;
		idx[sid]=i;
		a[i]=new Segment(sid, len, n1, n2);
		a[i]->input();
	}

	DSU dsu(2*n+5);

	for(int i{};i<n;i++){
		for(int x: a[i]->v[0]){
			if(a[idx[x]]->v[0].find(a[i]->sid)!=a[idx[x]]->v[0].end()){
				dsu.merge(a[i]->sid, x);
			}
			else if(a[idx[x]]->v[1].find(a[i]->sid)!=a[idx[x]]->v[1].end()){
				dsu.merge(a[i]->sid, x+n);
			}
		}

		for(int x: a[i]->v[1]){
			if(a[idx[x]]->v[0].find(a[i]->sid)!=a[idx[x]]->v[0].end()){
				dsu.merge(a[i]->sid+n, x);
			}
			else if(a[idx[x]]->v[1].find(a[i]->sid)!=a[idx[x]]->v[1].end()){
				dsu.merge(a[i]->sid+n, x+n);
			}
		}
	}


	gr.resize(2*n+5);
	for(int i{};i<n;i++){
		int u{dsu.find(a[i]->sid)};
		int v{dsu.find(a[i]->sid+n)};
		edwt[{u, v}]=a[i]->len;
		edwt[{v, u}]=a[i]->len;
		gr[u].insert({v, a[i]->len});
		gr[v].insert({u, a[i]->len});
	}

	for(int i{};i<n;i++){
		int u{dsu.find(a[i]->sid)};
		if(vis[u]==0 and !gr[u].empty()){
			cur.clear();
			st.clear();
			dfs(u, INT_MIN);
		}

		u=dsu.find(a[i]->sid+n);
		if(vis[u]==0 and !gr[u].empty()){
			cur.clear();
			st.clear();
			dfs(u, INT_MIN);
		}
	}
	cout<<ans<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
