#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6+5;

int vis[N];
vector<int> adj[N];
int init[N];
int goal[N];
int map[N];

void dfs(int src){
	vis[src]=1;
	for(auto& i: adj[src]){
		if(vis[i]) continue;
		map[i] = src;
	        dfs(i);
	}		
}

int main(){

	int n, r1, r2;
	cin >> n >> r1 >> r2;
	for(int i=1; i <= n; i++){
		if( i == r1 ) continue;
		int u; cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}

	dfs(r2);
	for(auto i=1; i <= n; i++){
		if(i==r2) continue;
		else cout << map[i] << " ";
	}
	cout << '\n' << endl;	
}
