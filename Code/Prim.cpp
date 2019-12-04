///....DH....///
#include <bits/stdc++.h>
#define task                "PRIM"
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

int prim() {
    int sum = 0;
    for(int i = 1; i <= n; i++)
        d[i] = INT_MAX;
    priority_queue < pii, vector < pii >, greater < pii > > pq;
    pq.push(mp(0, 1));
    while(pq.size() > 0) {
        pii u = pq.top(), pq.pop();
        if(d[u.sd] != u.ft)
            continue;
        sum += u.ft, d[u.ft] = 0;
        for(int i = 0; i < edge[u.sd].size(); i++) {
            pii v = edge[u.sd][i];
            if(d[v.sd] > v.ft) {
                d[v.sd] = v.ft;
                pq.push(mp(d[v.sd], v.sd));
            }
        }
    }
    return sum;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].pb(mp(w, v));
        edge[v].pb(mp(w, u));
    }
    for(int i = 1; i <= n; i++)
        edge[i].pb(mp(0, 0));
    cout << prim();
}
