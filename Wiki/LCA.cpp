#include <bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
ll logarit (ll n)
{
    ll res = 0;
    while((1 << res) <= n)
        res++;
    return res - 1;
}
ll d[maxn], p[maxn], n, m, u, v, x, y, t, t1;
ll T[1005][1005], dmax = 0;
vector <ll> g[maxn];
void dfs (ll u)
{
    d[u] = d[p[u]] + 1;
    dmax = max(d[u], dmax);
    for(ll i = 0; i < g[u].size(); i++)
    {
        ll v = g[u][i];
        if(!d[v])
        {
            p[v] = u;
            dfs(v);
        }
    }
}
void setup()
{
    for(ll i = 1; i <= 1000; i++)
    {
        g[i].clear();
        p[i] = d[i] = 0;
    }
    dmax = 0;
    for(ll i = 1; i <= 1000; i++)
        for(ll j = 1; j <= 1000; j++)
            T[i][j] = 0;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(ll l = 1; l <= t; l ++)
    {
        setup();
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            cin >> v;
            for(ll j = 1; j <= v; j++)
            {
                cin >> u;
                g[u].push_back(i);
                g[i].push_back(u);
            }
        }
        dfs(1);
        for(ll i = 1; i <= n; i++)
            T[i][0] = p[i];
        for(ll j = 1; (1 << j) <= dmax; j++)
            for(ll i = 1; i <= n; i++)
                T[i][j] = T[T[i][j-1]][j-1];
        cout << "Case " << l << ":\n";
        cin >> t1;
        while(t1 --)
        {
            cin >> x >> y;
            if(d[x] < d[y])
                swap(x,y);
            if(d[x] != d[y])
            {
                for(ll i = logarit(d[x] - d[y]); i >= 0; i--)
                {
                    if(d[T[x][i]] >= d[y])
                        x = T[x][i];
                    if(d[x] == d[y])
                        break;
                }
            }
            for(ll i = logarit(d[y]); i >= 0; i--)
            {
                if(T[x][i] != T[y][i])
                {
                    x = T[x][i];
                    y = T[y][i];
                }
            }
            if(x != y)
                cout << p[x] << "\n";
            else
                cout << x << "\n";
        }
    }
}
