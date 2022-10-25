#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
int largGroup = 0;

void dfs(int s, int& count){
	count++;
	visited[s] = 1;
	for(int i=0; i < adj_list[s].size(); i++){
		int a = adj_list[s][i];
		if(visited[a]) continue;
		visited[a] = 1;
		dfs(a, count);
	}
}

void testCase(int n, int m){
	largGroup = 0;
	for(int i = 0; i < N; i++){
		adj_list[i].clear();
		visited[i]=0;
	}

	for(int i=0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	int count = 0;
	dfs(1, count);
        largGroup = largGroup > count ? largGroup : count;
	
	for(int i=1; i < n; i++){
		if(!visited[i]){	
			count = 0;
			dfs(i, count);
	         	largGroup = largGroup > count ? largGroup : count;
		}
	}
	cout << largGroup << endl;
}

void allTestCases(){
	int t;
	cin >> t;
	while(t){
		int n , m;
		cin >> n >> m;
		testCase(n, m);
		t--;
	}
}

int main(){
	allTestCases();
}
