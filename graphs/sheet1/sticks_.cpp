#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N  = 1e5+10;
vector<int> adj_list[N];
int visited[N];
vector<int> ans;
int po[N];
int cyc = 0;

void dfs(int i){
	visited[i] = 1;
	po[i] = 1;
	for(int j=0; j < adj_list[i].size(); j++){
		int k = adj_list[i][j];
		if(!visited[k]) dfs(k);
		else{
			if(po[k] == 1) cyc = 1;
		}

	}
	po[i] = 0;
	ans.push_back(i);
}


int main(){	
	int n,m;
	while(cin >> n >> m, n||m){
		for(int i=1; i <= n;i++ ){
			visited[i] =  po[i] = 0;
			adj_list[i].clear();
			ans.clear();
		}

		for(int j=0; j < m; j++){
			int u, v;
			cin >> u >> v;
			adj_list[v].push_back(u);
		}

		cyc = 0;
		for(int j=n; j>=1 ; j--){
			if(!visited[j]){
				dfs(j);
			}	
		}

		if(cyc){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
	
//		cout << ans.size() << endl;
		for(int i = 0; i < ans.size() ; i++){
			cout << ans.at(i) << endl;
		}
	}
}
