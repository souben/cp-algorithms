#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
const int N = 1e3+10 ,M = 11,mod = 132120577;
const int inf = 1000000010;
 
int root1[N] , sz1[N];
int root2[N] , sz2[N];

void init(int root[],int sz[], int size){
        for(int i=1; i <= size; i++){
                root[i] = i;
                sz[i] = 1;
        }
}

int find(int root[], int x){
        if(x == root[x])
                return x;
        return root[x]=find(root, root[x]);
}

void unionSet(int root[], int sz[], int x, int y){
        int rootX = find(root, x);
        int rootY = find(root, y);
        if(rootX == rootY) return;
        if(sz[x] > sz[y]){
                root[rootY] = rootX;
                sz[x]+=sz[y];
        }else{
                root[rootX]=rootY;
                sz[y]+=sz[x];
        }
}

int connected(int root[], int x, int y){
        int rootX = find(root, x);
        int rootY = find(root, y);
        return rootX == rootY;
}

void testCase() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	init(root1, sz1, n);
	init(root2, sz2, n);
	for(int i=0; i<m1+m2; i++){
		int n1, n2; cin >> n1 >> n2;
		if( i < m1 ) unionSet(root1, sz1, n1, n2);
	        else unionSet(root2, sz2, n1, n2);
	}
	
	vector<pair<int,int>> ans;
	for(int i=1; i <=n; i++){
		for(int j=1; j<=n; j++){
			if(!connected(root1, i, j) && !connected(root2, i, j)){
				unionSet(root1, sz1, i, j);
				unionSet(root2, sz2, i, j);
				ans.emplace_back(i, j);
			}
		}
	}
	cout << ans.size() << endl;
	for(int i=0; i < ans.size() ; i++){
		cout << ans[i].F << " " << ans[i].S << endl;
	}
}
 
 
int32_t main() {
    Tsetso
    int tc = 1;
    while (tc--)
        testCase();
}
