#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N  = 1e5+10;
vector<int> adj_list[N];
int vis[N];
int dis[N];
vector<int> res;

void bfs(int src){
	queue<int> q;
	q.push(src);
	vis[src]=1;
	dis[src]=1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child=0;child < adj_list[src].size(); child++){
			if(vis[child]) continue;
			q.push(child);
			dis[child] = dis[src]+1;
		}
	}
}

int main(){
	int n_scen;
	cin >> n_scen;
	for(int i=0; i< n_scen; i++){
		int n, m;
		cin >> n >> m;
		for(int j = 0; j < n; j++){
			vis[j] = 0;
			adj_list[j].clear();
		}

		for(int j=0; j < m; j++){
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		bfs(1);
		for(int node=1; node < size(dis) ; node++){
			cout << dis[node] << endl;
		}
	}	
}
