#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N  = 1e5+10;
vector<int> adj_list[N];
int visited[N];
bool susp = false;
vector<int> res;

void dfs(int i, int type){
	// type: 1 for male , 2 for female 
	visited[i] = type;
	for(int j=0; j < adj_list[i].size(); j++){
		int k = adj_list[i][j];
		if(visited[k]){
		        if(visited[k] == type)       
				susp = true;
		       	continue;
		};
		dfs(k, 3-type);
	}
}

int main(){
	int n_scen;
	cin >> n_scen;
	for(int i=0; i< n_scen; i++){
		susp = false;
		int n, m;
		cin >> n >> m;
		for(int j = 0; j < n; j++){
			visited[j] = 0;
			adj_list[j].clear();
		}

		for(int j=0; j < m; j++){
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		dfs(1, 1);
		for(int j=1; j <=n ; j++){
			if(!visited[j]) dfs(j, 1);
		}
		cout << "Scenario #" << i+1 << ":" << endl;
		if(susp){
			cout << "Suspicious bugs found!" << endl;
		}else{
			cout << "No suspicious bugs found!" << endl;
		}
	}	
}
