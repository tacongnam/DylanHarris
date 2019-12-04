///....DH....///
#include <bits/stdc++.h>
#define task "CONNECT"
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

const int maxn = 200005;

int pa[400005], level[400005], n, m, p, q, d[3], to;
long long res, sum, MOD;

long long mul (long long A, long long B) {
    if(B == 0)
        return 0;
    if(B == 1)
        return A;
    long long x = mul(A, B / 2);
    if(B % 2 == 0)
        return (x + x) % MOD;
    else
        return (x + x + A) % MOD;
}

struct edge {
    int x, y;
    long long w;
    int type;
    bool operator < (const edge &P) {
        return w < P.w;
    }
};

vector <edge> li;

int Find(int u) {
    if(u == pa[u])
        return u;
    return pa[u] = Find(pa[u]);
}

void dsu(edge e) {
    int x = Find(e.x + e.type * to);
    int y = Find(e.y + e.type * to);
    if(x == y)
        return ;
    else {
        if(level[x] < level[y])
            pa[y] = x;
        else
            pa[x] = y;
        res = (res + mul(e.w, d[1 - e.type])) % MOD;
        d[e.type]--;
        return ;
    }
}

void mst() {
    sort(li.begin(), li.end());
    for(int i = 0; i < li.size(); i++)
        dsu(li[i]);
    return ;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".ans");
    cin >> n >> m >> p >> q >> MOD;
    int to = max(n, m) + 2;
    d[0] = n, d[1] = m;
    for(int i = 1; i <= 2 * to + 5; i++) {
        pa[i] = i;
        level[i] = 0;
    }
    for(int i = 1; i <= p; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        li.pb({u + to, v + to, w, 1});
        sum = (sum + mul(n, w)) % MOD;
    }
    for(int i = 1; i <= q; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        li.pb({u, v, w, 0});
        sum = (sum + mul(m, w)) % MOD;
    }
    mst();
    cout << (sum - res + MOD) % MOD;
}
