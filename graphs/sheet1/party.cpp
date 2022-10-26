#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e3+5;
vector<int> adj[N];
int vis[N];
int maxdp =1;
void dfs(int src, int dep){
dep++;
vis[src]++;
maxdp = dep > maxdp ? dep : maxdp ;
for(auto& i: adj[src]){
 dfs(i, dep);
}
}
int main(){
int n; cin >> n;
for(int i=1; i <= n; i++){
int u; cin >> u;
if( u == -1 ) continue;
adj[u].push_back(i);
}
dfs(1, 0);
for(int i = 1; i <=n ; i++)
if(!vis[i])
dfs(i, 0);
cout << maxdp << endl;
}
