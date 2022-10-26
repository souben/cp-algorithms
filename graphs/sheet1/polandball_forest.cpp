#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6+5;

int vis[N];
vector<int> adj[N];

void dfs(int src){
	vis[src]=1;
	for(auto& i: adj[src]){
		if(vis[i]) continue;
	        dfs(i);
	}		
}

int main(){

	int n; cin >> n;
	for(int i=1; i <= n; i++){
		int u; cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}

	dfs(1);
	int ans=1;
	for(auto i=1; i <= n; i++){
		if(!vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;	
}
