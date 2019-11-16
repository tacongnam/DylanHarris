#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
//#define f first
//#define s second
//#define int long long
using namespace std;

const int N = 200005;
int n, m;
int a[N], k[N], res[N];
vector < int > ke[N];
void DFS(int u)
{
    if(k[u] == 0)
    {
        res[u] = 1;
        return;
    }
    int t;
    if(k[u] == 1) t = 1e9;
    else t = 0;
    for(int v : ke[u])
    {
        DFS(v);
        if(k[u] == 1) t = min(t, res[v]);
        else t += res[v];
    }
    res[u] = t;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    FOR(i, 1, n)
    {
        int x, y;
        cin >> k[i] >> x >> y;
        if(x) ke[i].push_back(x);
        if(y) ke[i].push_back(y);
    }
    DFS(1);
    cout << a[m - res[1] + 1];
}
