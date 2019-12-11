https://vn.spoj.com/problems/MATCH1/

///....DH....///
#include <bits/stdc++.h>
#define task ""
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
#define For(i, s, n, m) for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m) for(int i = s; i >= n; i -= m)
using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

const int mod = 1e9 + 7;
const int maxn = 200005;

int n, m, res, x[maxn], d[maxn], y[maxn];
vector <int> g[maxn];

bool Find() {
    queue <int> qu;
    for(int i = 1; i <= m; i++) {
        if(x[i] == 0) {
            d[i] = 0;
            qu.push(i);
        }
        else
            d[i] = 1e9;
    }
    d[0] = 1e9;
    while(qu.size() > 0) {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(d[y[v]] == 1e9) {
                d[y[v]] = d[u] + 1;
                if(y[v] != 0)
                    qu.push(y[v]);
            }
        }
    }
    return (d[0] != 1e9);
}

bool dfs(int u) {
    if(u == 0)
        return true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(d[y[v]] == d[u] + 1)
            if(dfs(y[v]) == true) {
                x[u] = v, y[v] = u;
                return true;
            }
    }
    d[u] = 1e9;
    return false;
}

void GhepMax() {
    while(Find() == true) {
        for(int i = 1; i <= m; i++) {
            if(x[i] == 0)
                if(dfs(i) == true)
                    res++;
        }
    }
    cout << res << "\n";
    for(int i = 1; i <= m; i++)
        if(x[i] != 0)
            cout << i << " " << x[i] << "\n";
}

main() {
    cin >> m >> n;
    int u, v;
    while(cin >> u >> v)
        g[u].pb(v);
    GhepMax();
}
