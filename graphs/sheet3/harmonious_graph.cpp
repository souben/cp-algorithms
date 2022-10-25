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
pair<int, int> mm[N];

void init(int size){
        for(int i=1; i <= size; i++){
                root[i] = i;
                sz[i] = 1;
		mm[i].F = i; 
		mm[i].S = i;
        }
}

int find(int x){
        if(x == root[x])
                return x;
        return root[x]=find(root[x]);
}

void unionSet(int x, int y, int z){
        int rootX = find(x);	
        int rootY = find(y);
	//cout << "roots" << rootX << " " << rootY << endl;
        if(rootX == rootY) return;
	pair<int, int> px = mm[rootX];
	pair<int, int> py = mm[rootY];
	if(sz[x] > sz[y]){
                root[rootY] = rootX;
                sz[x]+=sz[y];
		if(z==0){
			mm[rootX].F = min(px.F, py.F);
			mm[rootX].S = max(px.S, py.S);
		}
        }else{
                root[rootX]=rootY;
                sz[y]+=sz[x];
		if(z==0){
			mm[rootY].F = min(px.F, py.F);
	       		mm[rootY].S = max(px.S, py.S);
		}
        }
}

int connected(int x, int y){
	int rx = find(x);
	int ry = find(y);
	return rx == ry;
}

bool comparator(const pair<int, int>& a, const pair<int , int>& b){
	return a.F < b.F;
}

void testCase() {
	int n, m;
	cin >> n >> m;
	init(n);
	for(int i=0; i<m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		unionSet(n1, n2, 0);
	}
	
	int j=1;
	for(int i =1; i <= n; i++){
		if(root[i] == i) mm[j++] = mm[i];
	}

	sort(begin(mm), begin(mm)+j, comparator);
	int t = 1;
	for(int i=2; i < j; i++ ){
		if(mm[i].F == mm[i].S ) continue;
		if(mm[t].S < mm[i].F){
			t++;
			mm[t].F = mm[i].F;
                	mm[t].S = mm[i].S;
		}else{
			mm[t].F = min(mm[t].F, mm[i].F);
			mm[t].S	= max(mm[t].S, mm[i].S);
		}		
	}
	
	int ans = 0;
	for(int i=1; i <= t; i++ ){
		int a = mm[i].F;
		int b = mm[i].S;
		cout << "t : " << a << " " << b << endl;
		for(int k=a; k < b; k++){
			if(!connected(k, k+1)){
				ans++;
				unionSet(k, (k+1) , 1);
			}
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
