#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6+5;

int vis[N];
vector<int> adj[N];
int init[N];
int goal[N];
vector<int> ans;

void dfs(int src, int isodd, int odd, int even){
	init[src] = isodd && odd%2 ? !init[src] : init[src];
	init[src] = !isodd && even%2 ? !init[src]: init[src];

	if(init[src] != goal[src]){
		init[src] = goal[src];
	        ans.push_back(src);
       		if(isodd) odd++;
		else even++;
	}		

	vis[src] = 1;

	for(auto& i: adj[src]){
		if(vis[i]) continue;
	        dfs(i, !isodd, odd, even);		
	}
}

int main(){

	int n; cin >> n;
	for(int i=1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i <= n; i++){
		int a; cin >> a;
		init[i] = a;
	}
	
	for(int i=1; i <= n; i++){
		int a; cin >> a;
		goal[i] = a;
	}
	
	dfs(1, 1, 0, 0);
	for(int i=1; i<=n; i++){
		if(!vis[i]){
	                int isodd = i%2!=0;
			dfs(i, isodd, 0, 0);
		}
	}

	cout << ans.size() << endl;
	for(auto& a: ans)
		cout << a << endl;

}
