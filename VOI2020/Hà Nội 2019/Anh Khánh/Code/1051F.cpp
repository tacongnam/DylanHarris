///....DH....///
#include <bits/stdc++.h>
#define task                "1051F"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pli                 pair<long long, int>
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

int vi[maxn], po[maxn], de[maxn], pa[20][maxn], n, m, q;
long long d[25][maxn], dist[20][maxn];
set < pair <int, int> > bad;
vector < pair <int, long long> > adj[maxn];

void dfs(int u, int p, long long w) {
    vi[u] = 1;
    de[u] = de[p] + 1;
    dist[0][u] = w;
    pa[0][u] = p;
    for(int i = 1; i <= log2(n); i++) {
        pa[i][u] = pa[i - 1][pa[i - 1][u]];
        dist[i][u] = dist[i - 1][u] + dist[i - 1][pa[i - 1][u]];
    }
    for(int i = 0; i < adj[u].size(); i++) {
        pair <int, long long> v = adj[u][i];
        if(vi[v.ft] == 0) {
            dfs(v.ft, u, v.sd);
            bad.erase(mp(max(u, v.ft), min(u, v.ft)));
        }
    }
}

long long lca (int u, int v) {
    if(de[u] > de[v])
        swap(u, v);
    long long ans = 0;
    for(int i = log2(n); i >= 0; i--)
        if((de[v] - de[u]) >= (1 << i))
            ans += dist[i][v], v = pa[i][v];
    if(u == v)
        return ans;
    for(int i = log2(n); i >= 0; i--) {
        if(pa[i][u] != pa[i][v]) {
            ans += dist[i][u] + dist[i][v];
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return ans + dist[0][u] + dist[0][v];
}

void dijkstra(int in, int pos) {
    memset(vi, 0, sizeof(vi));
    priority_queue < pli, vector < pli >, greater < pli > > pq;
    for(int i = 1; i <= n; i++)
        d[pos][i] = 1e16;
    d[pos][in] = 0;
    pq.push({0, in});
    while(pq.size() > 0) {
        pli u = pq.top();
        pq.pop();
        vi[u.sd] = 1;
        for(int i = 0; i < adj[u.sd].size(); i++) {
            pair <int, long long> v = adj[u.sd][i];
            if(vi[v.ft] == 0) {
                if(d[pos][v.ft] > d[pos][u.sd] + v.sd) {
                    d[pos][v.ft] = d[pos][u.sd] + v.sd;
                    pq.push(mp(d[pos][v.ft], v.ft));
                }
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //fi(task".inp");
    // fo(task".out");
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w)), adj[v].pb(mp(u, w));
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < adj[i].size(); j++) {
            pli v = adj[i][j];
            if(v.ft > i)
                bad.insert(mp(v.ft, i));
        }
    dfs(1, 1, 0);
    int cnt = 0;
    for(__typeof(bad.begin()) it = bad.begin(); it != bad.end(); it++) {
        pli ele = *it;
        dijkstra(ele.ft, ++cnt);
        po[ele.ft] = cnt;
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        long long tree = lca(u, v);
        long long ntree = LLONG_MAX;
        for(__typeof(bad.begin()) it = bad.begin(); it != bad.end(); it++) {
            pli  t = *it;
            Min(ntree, d[po[t.ft]][u] + d[po[t.ft]][v]);
        }
        cout << min(ntree, tree) << "\n";
    }
}
