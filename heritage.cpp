/*
ID: akhilen1
TASK: heritage
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int


class Node{
public:
	char ch;
	Node *left, *right;
	Node(char ch): ch(ch){
		left=right=nullptr;
	}
};

string ino, pre;

Node* construct(int lin, int rin, int lpre, int rpre){
	if(lin>rin){
		return nullptr;
	}

	Node* root{
		new Node(pre[lpre])
	};

	int idx{lin};
	while(idx<=rin){
		if(ino[idx]==pre[lpre])break;
		idx++;
	}

	root->left=construct(lin, idx-1, lpre+1, lpre+idx-lin);
	root->right=construct(idx+1, rin, lpre+idx-lin+1, rpre);

	return root;
}

string res;
void dfs(Node* node){
	if(node==nullptr){
		return;
	}
	dfs(node->left);
	dfs(node->right);
	res+=node->ch;
}

void solve(){
	cin>>ino>>pre;
	int n{(int)ino.size()};
	Node* root{
		construct(0, n-1, 0, n-1)
	};

	dfs(root);
	cout<<res<<"\n";
}

int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	solve();
	
	return 0;
}
