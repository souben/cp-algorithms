#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N  = 1e5+10;
vector<int> adj_list[N];
int visited[N];
vector<int> res;
unordered_map<string, int> mapping;
int lgc = 0;

// remove cycle from graph
/*void removeCycles(int i, int parent){
	visited[i] = 1;
	for(int j=0; j < adj_list[i].size(); j++){
		int k = adj_list[i][j];
		if(visited[k]){
			if(k != parent){			      	
				vector<int>::iterator it = adj_list[i].begin();
				it = it+j;
				adj_list[i].erase(it);	
			}
			continue;
		};
		removeCycles(k, i);
	}
}
*/

void dfs(int i){
	visited[i] = 1;
	lgc++;
	for(int j=0; j < adj_list[i].size(); j++){
		int k = adj_list[i][j];
		if(!visited[k]) dfs(k);
	}
}


int main(){	
	int n,m;
	while(cin >> n >> m, n||m){
		for(int i=1; i <= n;i++ ){
			visited[i] = 0;
			adj_list[i].clear();
		}
		mapping.clear();
		lgc = 0;

		for(int j = 1; j <= n; j++){
			string str ; cin >> str; 
			mapping.insert({{str, j}});		
		}

		for(int j=0; j < m; j++){
			string u, v;
			cin >> u >> v;
			adj_list[mapping.at(u)].push_back(mapping.at(v));
			adj_list[mapping.at(v)].push_back(mapping.at(u));
		}

		int c = 0;
		for(int j = 1; j <= n ; j++){
			lgc = 0;
			if(!visited[j]){
				dfs(j);
				c = lgc > c ? lgc : c;
			}	
		}
		cout << c  << endl;
	}
}
