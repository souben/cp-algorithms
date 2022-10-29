#include <iostream>
#include <vector>
#include <queue>


#define F first
#define S second

using namespace std;

const int N = 2e4+1;

int cnt = 0;
int vis[N];
int n, m;

void bfs(int n){
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while(q.size()){
		pair<int, int> a = q.front();
		if(a.F == m){
			cnt = a.S;
			return;
		}
		q.pop();
		vis[a.F] =  1;	
		if( a.F <= m/2+1 && !vis[2*a.F]) q.push( make_pair(2 * a.F, a.S + 1));
		if( a.F-1 > 0 && a.F <= m+1 && !vis[a.F-1]) q.push(make_pair(a.F-1, a.S + 1 ));

	}
}

int main(){
	cin >> n >> m;
	if( n > m ) cnt = n-m;
	else if ( n == m ) cnt = 0;
	else bfs(n);
	cout << cnt << endl;
}
