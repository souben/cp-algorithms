#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
vector<int> res;
queue<int> q;

void bfs(int source){
	q.push(source);
	visited[source] = 1;
	res.push_back(source);
	while(!q.empty()){
		int front = q.front();
		for(int i=0; i < adj_list[front].size(); i++){
			int a = adj_list[front][i];
			if(visited[a]) continue;
			q.push(a);
			visited[a] = 1;
			res.push_back(a);
		}
		q.pop();
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i < m ; i++){
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	bfs(1);
	int ans = 1;
	for(int i=1; i <= n; i++){
		if(!visited[i]){
			bfs(i);
			ans++;
		}
	}
	if(ans==1 && n==m+1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
	
