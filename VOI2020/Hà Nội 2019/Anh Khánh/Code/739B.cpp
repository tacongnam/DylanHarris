/**

- log2(200000) ~ 17,... (test 15)

**/

///....DH....///
#include <bits/stdc++.h>
#define task                "739B"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pil                 pair<int, long long>
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
/** size of array **/       const int maxn = 300005;

int n, p[22][maxn], c[maxn];
long long d[22][maxn], a[maxn];
vector < pil > g[maxn];

void dfs(int u, int pa, long long w) {
    d[0][u] = w;
    p[0][u] = pa;
    for(int i = 1; i <= 19; i++) {
        d[i][u] = d[i - 1][u] + d[i - 1][p[i - 1][u]];
        p[i][u] = p[i - 1][p[i - 1][u]];
    }
    for(int i = 0; i < g[u].size(); i++) {
        pil v = g[u][i];
        if(v.ft != pa) {
            dfs(v.ft, u, v.sd);
            c[u] += c[v.ft];
        }
    }
}

int update(int u, long long dist) {
    int _u = u;
    for(int i = 19; i >= 0; i--)
        if(dist - d[i][u] >= 0 && p[i][u] != 0)
            dist -= d[i][u], u = p[i][u];
    c[p[0][_u]]++, c[p[0][u]]--;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(mp(i, y));
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n; i++)
        update(i, a[i]);
    dfs(1, 0, 0);
    for(int i = 1; i <= n; i++)
        cout << c[i] << " ";
}
