#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e2+2;

vector<int> adj[N];
vector<int> path;
int root[N];
int in_deg[N];
int vis[N];

void dfs(int src){
	path.push_back(src);
	vis[src] = 1;
	for(auto& i: adj[src]){
		in_deg[i]--;
		if(!in_deg[i]) dfs(i);
	} 	
}




int main(){

	int n, m;
	while(cin >> n >> m && (n || m)){
		
		path.clear();
		for(int i=1; i <= n; i++){
		       adj[i].clear();
		       in_deg[i] = 0;
		       root[i] = i;
		       vis[i] = 0;
		}	       
		
		for(int i=1; i <= m; i++){
			int u, v; cin >> u >> v;
			if(root[u] != root[v]){
				adj[u].push_back(v);
				in_deg[v]++;
				root[root[v]] = root[u];
				for(int j=1; j <=n ; j++)
					if(root[j]==root[v]) root[j] = root[u];
			}
		}

		for(auto i=1; i <= n; i++){
			if(!in_deg[i] && !vis[i]) dfs(i);
		}		

		for(auto& i : path) cout << i << " ";
		cout << '\n';
	}
}
