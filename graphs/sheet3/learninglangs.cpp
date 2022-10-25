#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 1e2;
vector<pair<int, int>> pairs;

class DSU {
	public:
	vector<int> root;
	vector<int> rank;
	void init();
	DSU(int size) : root(size), rank(size) { init(); }
	void unionSet(int x, int y);
	int find(int x);
	int connected(int x, int y);

};

void DSU::init(){
	for(int i=0; i < root.size(); i++){
		root[i] = i;
		rank[i] = 1;
	}
}

int DSU::find(int x){
	if(x == root[x])
		return x;
	return root[x]=find(root[x]);
}

void DSU::unionSet(int x, int y){
	int rootX = find(x);
	int rootY = find(y);
	if(rootX == rootY) return;
	if(rank[x] < rank[y])
		root[rootX] = rootY;
	else if( rank[y] < rank[x] )
		root[rootY] = rootX;
	else{
		root[rootY] = rootX;
		rank[x]+=1;
	}
}

int DSU::connected(int x, int y){
	int rootX = find(x);
	int rootY = find(y);
	return rootX == rootY;
}
	
		
int main(){
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	vector<int> langs[101];
	int cost = 0;
	int lang = 1;
	vector<int> r;
	for(int i=0; i < n ; i++){
		int l; cin >> l;
		if(l == 0) r.push_back(i);
		while(l > 0){
			int a; cin >> a;
			lang = a; 
			langs[a].push_back(i);
			l--;
		}
	}

	int l = r.size();
	cost += l;
	while(l > 0){
		langs[lang].push_back(r[l-1]);
		l--;
	}

	for(int i = 1; i <= m; i++){  
		if(langs[i].size() <= 1) continue;		
		for(int j=1; j < langs[i].size(); j++){
			if(!dsu.connected(langs[i][j], langs[i][j-1]))
				dsu.unionSet(langs[i][j], langs[i][j-1]);		
		}
	}
	

	for(int i=1; i < n; i++){
		if(!dsu.connected(i, 0)){
			dsu.unionSet(i, 0);
			cost++;
		}
	}
	cout << cost << endl;

}


