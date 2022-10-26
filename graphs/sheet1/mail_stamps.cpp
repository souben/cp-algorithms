#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 1e5+2;
vector<int> adj[N];
int deg[N];
unordered_map<int, int> ntoi;
unordered_map<int, int> iton;

void dfs(int src, int par){
	for(auto& i: adj[src]){
		if(i == par) continue;
		dfs(i, src);
	}
	cout << iton[src] << " ";
}


int main(){
	int n; cin >> n;
	int st;
	int k = 1;
	
	for(int i=1; i <= n; i++){
		int u, v; cin >> u >> v;
		if(ntoi.find(u) == ntoi.end()){
			ntoi[u] = k; 
			iton[k] = u;
			k++;
		}

		if(ntoi.find(v) == ntoi.end()){
			ntoi[v] = k;
			iton[k] = v;
			k++;
		}
		adj[ntoi[u]].push_back(ntoi[v]);
		adj[ntoi[v]].push_back(ntoi[u]);
		deg[ntoi[u]]++; deg[ntoi[v]]++;
	}

	for(int i=1; i < k; i++)
		if(deg[i] == 1){
			st = i;
			break;
		}

	dfs(st, -1);
	cout << '\n' << endl;
}
