#include <iostream>
#include <vector>

using namespace std;

const int N  = 1e5+10;

vector<int> res;
int vis[N];
vector<int> stack;
vector<int> graph[N];

void dfs(int a){
        cout << "call ... " << stack[0] << endl;
	if(stack.size()==0) return;
	stack.pop_back();
	for(int i=0; i < graph[a].size(); i++){
		if(vis[graph[a][i]] == 1) continue;
		vis[graph[a][i]] = 1;
		stack.push_back(graph[a][i]);
		res.push_back(graph[a][i]);
		dfs(graph[a][i]);
	}
}

int main(){
	cout << "Enter number of edges: " << endl;
	int n; cin >> n;
	cout << "Enter number of nodes: " << endl;
	int m; cin >> m;
	for(int i = 1; i <= n; i++ ){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1; i <= m; i++){
		cout << i << " -> ";
		for(int j=0; j < graph[i].size();j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	res.push_back(4);
	stack.push_back(4);
	vis[4] = 1;
	dfs(4);
	for(int i=0; i < res.size();i++){
		cout << res[i] << endl;
	}
}
