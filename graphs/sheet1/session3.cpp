#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
const int N = 2e5+10 ,M = 11,mod = 132120577;
const int inf = 1000000010;
 
int par[N] , sz[N];
 
// initialize DSU
 
void init( int n )
{
    for ( int i = 1;  i<= n ; i++)
        par[i] = i , sz[i] = 1;
}
 
int findparent( int u )
{
    if( par[u] == u)
        return u;
    return par[u] = findparent(par[u]);
}
// m connection
// O(m log(n)) ~ O(n)
void connect( int u , int v)
{
    // O(log(n))
    u = findparent(u);
    v = findparent(v);
    if ( u == v)
        return;
    if(sz[u] > sz[v])
    {
        par[v] = u ;
        sz[u] += sz[v];
    }
    else
    {
        par[u] = v;
        sz[v] += sz[u];
    }
}
 
void testCase() {
 
 
}
 
 
int32_t main() {
    Tsetso
    int tc = 1;
//    cin >> tc;
    while (tc--)
        testCase();
}
