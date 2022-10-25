#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ld long double
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 2e5+10 ,M = 20 ,mod = 998244353;
const ll inf = 2e18;

int n ,m , in[N], out[N],vis[N];
vector < pair < int , int > > g[N];

vector < int > path;
void Tour( int node)
{
    while(!g[node].empty())
    {
        int nxt = g[node].back().F , edgeidx = g[node].back().S;
        g[node].pop_back();
        if(!vis[edgeidx])
        {
            vis[edgeidx] = 1;
            Tour(nxt);
        }
    }
    path.push_back(node);
}

void testCase()
{
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back({v,i});
        in[v]++,out[u]++;
    }
    for ( int i = 2 ; i < n ; i++)
    {
        if(in[i] != out[i])
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if(out[1] != in[1] + 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if(out[n] != in[n]-1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    Tour(1);
    if(path.size() != m+1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(path.begin(),path.end());
    for ( int i = 0 ; i <= m ;i++)
        cout << path[i] << ' ';
    cout << '\n';
}

int32_t main() {
    Tsetso
    int tc = 1;
//    cin >> tc;
    while(tc--)
        testCase();

}
