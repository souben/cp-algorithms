#include <iostream>
#include <vector>
#include <queue>


using namespace std;


const int N = 1e5+2; 
vector<int> adj[N];
int vis[N];


void bfs(int src){
	queue<int> q;
	q.push(src);
	while(q.size()){
		int a = q.front();
		vis[a] = 1;
		q.pop();
		for(auto& i: adj[a]){
			if(!vis[i]) q.push(i);
		}
	}
}

char* test_case(int n, int m){
	if(n != m+1) return (char*)"NO";
	for(int i=0; i < m; i++){
	        int u, v; cin >> u >> v;
		adj[u].push_back(v);	
		adj[v].push_back(u);
	}
	
	bfs(1);
	int cnt = 1;
	for(int i=1; i <=n; i++){
		if(!vis[i]){
			return (char*)"NO";
		}
	}
	return (char*)"YES";
}

int main(){
	int n, m;
	cin >> n >> m;
	cout << test_case(n, m) << endl;
}
