///....DH....///
#include <bits/stdc++.h>
#define task                "AMN"
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
/** size of array **/       const int maxn = 505;

int m, n, x, y, c[maxn];
long long a;
vector < pli > vt[maxn];

bool cmp (vector < pli > &a, vector < pli > &b) {
    return a[0].ft > b[0].ft;
}

bool cmp2 (pli a, pli b) {
    return c[a.sd] < c[b.sd];
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> m >> n >> x >> y;
    For(i, 1, m, 1) {
        For(j, 1, n, 1) {
            cin >> a;
            vt[i].pb(mp(a, j));
        }
        sort(vt[i].begin(), vt[i].end(), greater < pli > ());
    }
    sort(vt + 1, vt + m + 1, cmp);
    /// Cố định hàng đầu tiên
    For(i, 0, n - 1, 1)
        c[vt[1][i].sd] = i;

    /// Từ hàng đầu tiên suy ra các hàng còn lại
    For(i, 2, m, 1)
        sort(vt[i].begin(), vt[i].end(), cmp2);
    sort(vt + 2, vt + m + 1, cmp);
    For(i, 1, m, 1)
        For(j, 0, n - 1, 1)
            if(i == x && j == y - 1) {
                cout << vt[i][j].ft;
                return 0;
            }
}
