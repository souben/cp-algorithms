#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int N = 1e5;
vector<pair<int, int>> pairs;

class DSU {
	vector<int> root;
	vector<int> rank;
	public:
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
	int rootX = root[x];
	int rootY = root[y];
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
	int n;
	cin >> n;
	string valya, tolya;
	cin >> valya >> tolya;
	DSU dsu(26);
	for(int i=0; i < valya.length(); i++){
		int a = valya[i] -'a';
		int b = tolya[i] -'a';
		if(dsu.connected(a, b)) continue;
		dsu.unionSet(a, b);
		pairs.push_back({a, b});
	}

	for(int i = 0; i < pairs.size(); i++){
		char c = 'a'+pairs[i].first;
		char b = 'a'+pairs[i].second;
		cout << c << " " << b << endl;
	}
}


