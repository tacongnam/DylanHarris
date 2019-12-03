///....DH....///
#include <bits/stdc++.h>
#define task                "Built"
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

struct edge {
    int x, y, w;
    bool operator < (const edge &P) {
        return w < P.w;
    }
} a[maxn], b[maxn];
int cnt, n, res, p[maxn];

bool cmpx (edge P, edge Q) {
    return P.x < Q.x;
}

bool cmpy (edge P, edge Q) {
    return P.y < Q.y;
}

int Find(int u) {
    if(u == p[u])
        return u;
    return p[u] = Find(p[u]);
}

int dsu(edge e) {
    int x = Find(e.x);
    int y = Find(e.y);
    if(x == y)
        return 0;
    p[x] = y;
    return e.w;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].w = i;
    }
    sort(a + 1, a + n + 1, cmpx);
    for(int i = 1; i < n; i++) {
        b[++cnt].x = a[i].w;
        b[cnt].y = a[i + 1].w;
        b[cnt].w = min(abs(a[i].x - a[i + 1].x), abs(a[i].y - a[i + 1].y));
    }
    sort(a + 1, a + n + 1, cmpy);
    for(int i = 1; i < n; i++) {
        b[++cnt].x = a[i].w;
        b[cnt].y = a[i + 1].w;
        b[cnt].w = min(abs(a[i].x - a[i + 1].x), abs(a[i].y - a[i + 1].y));
    }
    sort(b + 1, b + cnt + 1);
    for(int i = 1; i <= n; i++)
        p[i] = i;
    for(int i = 1; i <= cnt; i++) {
        res += dsu(b[i]);
    }
    cout << res;
}
//6 8 3 4 9 12 19 18 1 13 5 7 6 -> 8
