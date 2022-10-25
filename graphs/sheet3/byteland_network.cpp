#include <bits/stdc++.h>

using namespace std;

vector<int> root;
vector<int> sz;

void init(int size){
	root.resize(size);
	sz.resize(size);
	for(int i=1; i <= size; i++){
		root[i] = i;
		sz[i] = 1;
	}
}

int find(int x){
	if(x == root[x])
		return x;
	return root[x]=find(root[x]);
}

void unionSet(int x, int y){
	int rootX = find(x);
	int rootY = find(y);
	if(rootX == rootY) return;
	if(sz[x] > sz[y]){
		root[rootY] = rootX;
		sz[x]+=sz[y];
	}else{
		root[rootX]=rootY;
		sz[y]+=sz[x];
	}
}

int connected(int x, int y){
	int rootX = find(x);
	int rootY = find(y);
	return rootX == rootY;
}
	
		
int main(){

	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	
	int s;
	cin >> s;
	for(int i = 0 ; i < s; i++){
		int n; cin >> n;
		init(n);
		vector< pair< int,pair<int, int> > > edges;
		for(int i=1; i <= n ; i++){
			string name; cin >> name;
			int p; cin >> p;
			while(p > 0){
				int neigh, cost ; 
				cin >> neigh >> cost ;
				edges.push_back({cost, { i, neigh }});
				p--;
			}
		}
		sort(edges.begin(), edges.end());
		long long gcost = 0;
		for(int i = 1; i <= edges.size(); i++){  	
			int a = edges[i].second.first;
			int b = edges[i].second.second;
			if(connected(a, b)) continue;
			unionSet(a, b);
			gcost += edges[i].first;
		}
		cout << gcost << endl;
	}
}
