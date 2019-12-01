///....DH....///
#include <bits/stdc++.h>
#define task                "CHECKNET"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 200005;

int n, m, d[maxn], pa[20][maxn], c[maxn], res;
vector <int> g[maxn];

void dfs(int u, int p) {
    d[u] = d[p] + 1;
    pa[0][u] = p;
    for(int i = 1; i <= log2(n); i++)
        pa[i][u] = pa[i - 1][pa[i - 1][u]];
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != p) {
            dfs(v, u);
            c[u] += c[v];
        }
    }
    if(c[u] > 0 && u != 1)
        res++;
    return ;
}

void lca(int u, int v) {
    int uu = u, vv = v;
    if(d[u] > d[v])
        swap(u, v), swap(uu, vv);
    for(int i = log2(n); i >= 0; i--)
        if((d[v] - d[u]) >= (1 << i))
            v = pa[i][v];
    if(u == v) {
        c[vv]++, c[uu]--;
        return ;
    }
    for(int i = log2(n); i >= 0; i--)
        if(pa[i][u] != pa[i][v])
            u = pa[i][u], v = pa[i][v];
    u = pa[0][u], v = pa[0][v];
    c[vv]++, c[uu]++, c[v] -= 2;
    return ;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        lca(u, v);
    }
    dfs(1, 1);
    cout << res;
}
