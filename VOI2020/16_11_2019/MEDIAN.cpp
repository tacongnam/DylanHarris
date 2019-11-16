///....DH....///
#include <bits/stdc++.h>
#define task "MEDIAN"
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

const int mod = 1e9 + 7;
const int maxn = 200005;
int n, m, r, c, med, a[1005][1005], ar[1000005], F[1005][1005], cnt;
bool check(int id) {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            F[i][j] = F[i-1][j] + F[i][j-1] - F[i-1][j-1] + (a[i][j] <= id);
    for(int i = 1; i <= (n - r + 1); i++) {
        for(int j = 1; j <= (m - c + 1); j++) {
            int i2 = i + r - 1, j2 = j + c - 1;
            int t = F[i2][j2] - F[i-1][j2] - F[i2][j-1] + F[i-1][j-1];
            if(t >= med)
                return true;
        }
    }
    return false;
}

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            ar[++cnt] = a[i][j];
        }
    sort(ar + 1, ar + n * m + 1);
    med = (r * c + 1) / 2;
    int l = 1, r = n * m;
    while(l < r) {
        int tb = (l + r) / 2;
        if(check(ar[tb]) == true)
            r = tb;
        else
            l = tb + 1;
    }
    cout << ar[l];
}
