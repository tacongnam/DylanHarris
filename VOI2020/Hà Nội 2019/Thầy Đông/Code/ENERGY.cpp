/**
- sum, l, r để long long
- sau khi lấy
**/
///....DH....///
#include <bits/stdc++.h>
#define task                "ENERGY"
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
/** size of array **/       const int maxn = 1005;

vector <int> g[maxn];
int vi[maxn], n, r, x[maxn], y[maxn], z[maxn], match[maxn], cnt;
long long w[maxn], sum;
int dfs(int u) {
    if(vi[u] == cnt)
        return 0;
    vi[u] = cnt;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(match[v] == 0 || (dfs(match[v]) != 0)) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

bool dist (int x1, int y1, int z1, int x2, int y2, int z2) {
    long long k = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
    return (k <= 1);
}

bool solve(long long e) {
    reset(vi, 0);
    reset(match, 0);
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 1; i <= n; i++)
        if(abs(x[i] + y[i] + z[i]) % 2 == 0) {
            for(int j = 1; j <= n; j++) {
                if(abs(x[j] + y[j] + z[j]) % 2 == 1) {
                    if(dist(x[i], y[i], z[i], x[j], y[j], z[j]) == true && w[i] + w[j] >= e)
                        g[i].push_back(j);
                }
            }
        }
    int s = 0;
    for(cnt = 1; cnt <= n; cnt++)
        s += dfs(cnt);
    //cout << s << "\n";
    for(int i = 1; i <= n; i++)
        if(abs(x[i] + y[i] + z[i]) % 2 == 0) {
            for(int j = 1; j <= n; j++) {
                if(abs(x[j] + y[j] + z[j]) % 2 == 1) {
                    if(dist(x[i], y[i], z[i], x[j], y[j], z[j]) == true && w[i] + w[j] >= e)
                        g[j].push_back(i);
                }
            }
        }
    for(int i = 1; i <= n; i++) {
        if(match[i] == 0) {
            if(w[i] >= e) {
                s++;
                continue;
            }
            bool ok = false;
            for(int j = 0; j < g[i].size(); j++)
                if(w[i] + w[g[i][j]] >= e) {
                    s++;
                    ok = true;
                    break;
                }
            if(ok == false)
                return false;
        }
    }
    if(s > r)
        return false;
    return true;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n >> r;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        sum += w[i];
    }
    long long l = -1, r = sum;
    while(r - l > 1) {
        long long tb = (l + r) / 2;
        if(solve(tb) == true)
            l = tb;
        else
            r = tb;
    }
    if(solve(r) == true)
        cout << r;
    else
        cout << l;
}
