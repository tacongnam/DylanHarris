///....DH....///
#include <bits/stdc++.h>
#define task                ""
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

int n, a[maxn], vi[maxn], dem, sz;
long long res, po[maxn], ans;
vector <int> g[maxn];

void dfs(int u, int p, int d) {
    bool callpa = false;
    vi[u] = d;
    sz++;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == p && callpa == false)
            callpa = true;
        else {
            if(vi[v] != 0) {
                if(vi[v] < d) {
                    ans = (po[d - vi[v] + 1] - 2 + mod) % mod;
                    dem = d - vi[v] + 1;
                }
                continue;
            }
            dfs(v, u, d + 1);
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].pb(i), g[i].pb(a[i]);
    }
    po[0] = 1;
    for(int i = 1; i <= n; i++)
        po[i] = (po[i - 1] * 2) % mod;
    res = 1;
    for(int i = 1; i <= n; i++) {
        if(vi[i] == 0) {
            dem = 0, sz = 0;
            dfs(i, i, 1);
            res = ((res * ans) % mod * po[sz - dem]) % mod;
        }
    }
    cout << res;
}
