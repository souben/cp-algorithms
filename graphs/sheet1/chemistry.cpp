#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6+5;

int vis[N];
vector<int> adj[N];
long long maxD=1;

void dfs(int src){
	vis[src]=1;
	for(auto& i: adj[src]){
		if(vis[i]) continue;
	        maxD *= 2;
		dfs(i);
	}		
}

int main(){

	int n, m;
	cin >> n >> m;
	for(int i=1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	for(auto i=1; i <= n; i++){
		if(vis[i]) continue;
		dfs(i);
	}

	cout << maxD << endl;	
}
