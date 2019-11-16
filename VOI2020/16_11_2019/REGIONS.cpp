///....DH....///
#include <bits/stdc++.h>
#define task "REGIONS"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<long long, long long>
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

const long long mod = 1e9 + 7;
const long long maxn = 200005;

long long k;
int d[maxn], cnt, n, m;
vector <int> adj[maxn];
pair <long long , long long> sz[maxn];

void dfs(int u) {
    sz[cnt].ft++;
    sz[cnt].sd += adj[u].size();
    d[u] = cnt;
    For(i, 0, int(adj[u].size()) - 1, 1) {
        int v = adj[u][i];
        if(d[v] == 0)
            dfs(v);
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> n >> m >> k;
    For(i, 1, m, 1) {
        int u, v;
        cin >> u >> v;
        if(u == v)
            continue;
        adj[u].pb(v), adj[v].pb(u);
    }
    For(i, 1, n, 1) {
        if(d[i] == 0) {
            cnt++;
            dfs(i);
            sz[cnt].sd = sz[cnt].sd / 2;
        }
    }
    sort(sz + 1, sz + cnt + 1, greater <pii> ());
    long long sum = 0, in = 1, k1 = k;
    for(int i = 1; i <= cnt; i++){
        k -= ((sz[i].ft * (sz[i].ft - 1) / 2) - sz[i].sd);
        if(k < 0)
            break;
    }
    while(k > 0 && in <= cnt) {
        sum += sz[in].ft, in++;
        k -= sum * sz[in].ft; //overflow (28 / 100)
    }
    cout << max(1ll, cnt - k1) << " " << (cnt - in + 1);
}
