#include <iostream>
#include <math.h>

using namespace std;

#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
const int N = 2e5+10 ,M = 11,mod = 132120577;
const int inf = 1000000010;
 
int root[N];
int sz[N];
int nc = 0;

void init(int size){
	nc = size;
	for(int i=1; i<= size; i++){
		root[i] = i;
		sz[i] = 1;
	}
}

int find(int x){
	if(x=root[x]) return x;
	return root[x]=find(root[x]);
}

void unionSet(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if(rx == ry) return;
	if(sz[x]<sz[y]){
		root[rx] = ry;
		sz[y]+= sz[x];
	}else{
		root[ry] = rx;
		sz[x]+= sz[y];
	}
}


int main(){
	int n, k;
	cin >> n >> k;
	init(n);
	for(int i=1; i<n ;i++){
		int n1, n2, e;
		cin >> n1  >> n2 >> e;
		if(e) {
			unionSet(n1, n2);
			nc--;
		}
	}

	if(nc == n){
		cout << 0 << endl;
	        return 0;
	}	
	
	ll x = 1;
	int t = k;
	
	while(t > 0){
		x*=n;
		x%=mod;
		t--;
	}
	ll ng = 0;
	
	int sc = 0;
	for(int i=1; i<=n; i++)
		if(root[i]==i && sz[i]==1) sc++;
		
	int mc = nc - sc;
	for(int i=1; i<=n; i++){
		if(root[i]==i && sz[i]==1){
			int k1 = k/2;
			int k2 = k-k1;
			ll pow1 = pow(2, k1);
		        ll pow2 = pow(2, k2);
			ng=ng+((mc%mod)*(pow1%mod)*(pow2%mod))%mod;
			ng%=mod;
		}
	}
	ng+=(n-2*sc);
	cout << x-ng <<endl;
}
