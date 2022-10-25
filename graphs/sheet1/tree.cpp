#include <iostream>
#include <vector>
#include <algorithm>
#include < unorderd_map>

using namespace std;

const int N  = 1e5+10;
vector<int> adj_list[N];
int visited[N];
bool susp = false;
vector<int> res;
typedef unordermap<string, int> mapping;

void dfs(int i, int parent){
	visited[i] = 1;
	for(int j=0; j < adj_list[i].size(); j++){
		int k = adj_list[i][j];
		if(visited[k]){
			if(k != parent){
			        cout << "im visited" << endl;	
				vector<int>::iterator it = adj_list[i].begin();
				it = it+j;
				adj_list[i].erase(it);	
			}
			continue;
		};
		dfs(k, i);
	}
}

int main(){
	int n_scen;
	cin >> n_scen;
	for(int i=0; i< n_scen; i++){
		cout << "test case number #" << i << " --------" << endl;
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

		for(int j = 1; j <= n; j++){
			cout << j << ": ";
			for(int i=0; i < adj_list[j].size(); i++){
				cout << adj_list[j][i] << " ";
			}
			cout << " " << endl;
		}



		dfs(1, -1);
		cout << "----" << endl;
		for(int j=1; j <=n ; j++){
			if(!visited[j]) dfs(j, -1);
		}	
		cout << " ----------------- "<< endl;
		for(int j = 1; j <= n; j++){
			cout << j << ": ";
			for(int i=0; i < adj_list[j].size(); i++){
				cout << adj_list[j][i] << " ";
			}
			cout << " " << endl;
		}


	}
}
