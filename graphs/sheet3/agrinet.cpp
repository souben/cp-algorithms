#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
const int N = 2e5+10 ,M = 11,mod = 132120577;
const int inf = 1000000010;
 
int root[N] , sz[N];

void init(int size){
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

bool comparator(const pair<int, pair<int, int>>& a, const pair<int, pair<int,int>>& b){
	return a.F < b.F ;
}

void testCase() {
	int n;
        cin >> n;
	init(n);
	vector<pair<int, pair<int, int>>> dis;
	for(int i=0; i < n; i++){
		for(int j=0; j<n; j++){
			int a; cin >> a;
			if(i < j){
				dis.push_back({a, {i+1, j+1}});
			}
		}
	}

	sort(dis.begin(), dis.end(), comparator);

	int ans = 0;
	for(int i = 0; i< dis.size() ; i++){
		int d = dis[i].F;
		int n1 = dis[i].S.F;
		int n2 = dis[i].S.S; 
		if(!connected(n1, n2)){
			unionSet(n1, n2);
			ans += d;
		}
	}
	cout << ans << endl;
}
 
 
int32_t main() {
    Tsetso
    int tc = 1;
    while (tc--)
        testCase();
}
