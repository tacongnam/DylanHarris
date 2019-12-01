///....DH....///
#include <bits/stdc++.h>
#define task                "BGRAPH"
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

/** MOD **/                 const long long mod = 998244353;
/** size of array **/       const int maxn = 300005;

long long po[maxn], d[maxn], n, m, res, x, y, s[maxn];
vector <int> adj[maxn];

void calc2() {
    po[0] = 1;
    for(int i = 1; i <= n; i++)
        po[i] = (po[i - 1] * 2) % mod;
}

int dfs(int u, int sta) {
    d[u] = 1;
    s[u] = sta;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(d[v] == 0) {
            if(sta == 0)
                x++, dfs(v, 1);
            else
                y++, dfs(v, 0);
        }
        else {
            if(s[v] == s[u]) {
                cout << 0;
                exit(0);
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    calc2();
    res = 1;
    for(int i = 1; i <= n; i++) {
        if(d[i] == 0) {
            x = 1, y = 0;
            dfs(i, 1);
            res = (res * (po[x] + po[y])) % mod;
        }
    }
    cout << res;
}
