#include <bits/stdc++.h>



int mod = 1e9+7;
int N = 1e6+5;
vector<int> adj[N];
int in_deg[N];

void dfs(int src){
	cout << src << endl;
	for(int i=0; i < adj[src].size(); i++){
		int k = adj[src][i];
		in_deg[k]--;
		if(in_deg[k]==0) dfs(k);
	}
}


int main(){
	int n, m;
	while(cin >> n >> m && ( n || m )){
		memset()




