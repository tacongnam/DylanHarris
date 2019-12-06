///....DH....///
#include <bits/stdc++.h>
#define task "TREE"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pil pair<int, long long>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
#define For(i, s, n, m) for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m) for(int i = s; i >= n; i -= m)
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 200005;

int d[maxn], n, res, ans;
vector <int> g[maxn];

pil dp[maxn][3];

void Max(pil &a, pil b, pil c) {
    if(b.ft > c.ft) {
        a.ft = (a.ft + b.ft) % mod;
        a.sd = (a.sd * b.sd) % mod;
    }
    else if(b.ft < c.ft){
        a.ft = (a.ft + c.ft) % mod;
        a.sd = (a.sd * c.sd) % mod;
    }
    else {
        a.ft = (a.ft + c.ft) % mod;
        a.sd = (a.sd * (b.sd + c.sd)) % mod;
    }
}

/// 2 ^ n * n
void dfs(int u, int p) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != p) {
            dfs(v, u);
            Max(dp[u][0], mp(dp[v][0].ft - 1, dp[v][0].sd), dp[v][1]);
            Max(dp[u][1], dp[v][0], dp[v][1]);
        }
    }
    return ;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = mp(1, 1);
        dp[i][1] = mp(0, 1);
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 1);
    pil res = mp(0, 1);
    Max(res, dp[1][0], dp[1][1]);
    cout << res.ft << "\n" << res.sd;

}
