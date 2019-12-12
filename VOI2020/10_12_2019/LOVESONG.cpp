///....DH....///
#include <bits/stdc++.h>
#define task "LOVESONG"
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

template <typename R, typename D> inline void Min(R &a, D b)
{
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b)
{
    if(a<b)
        a=b;
}

const int mod = 1e9 + 7;
const int maxn = 200005;

int n, m, vi[maxn], match[maxn], a[maxn], b[maxn], res, cnt;
vector <int> g[maxn];

int Find(int u) {
    if(vi[u] == cnt)
        return 0;
    vi[u] = cnt;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(match[v] == 0 || Find(match[v]) != 0) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] != b[j])
                g[i].pb(j);
    for(cnt = 1; cnt <= n; cnt++)
        res += Find(cnt);
    cout << res << "\n";
    for(int i = 1; i <= m; i++)
        if(match[i] != 0)
            cout << match[i] << " " << i << "\n";
}
