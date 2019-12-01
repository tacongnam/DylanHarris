///....DH....///
#include <bits/stdc++.h>
#define task "RESORT"
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
const int maxn = 2005;
int T[maxn][maxn], F[maxn][maxn], n, m, p, q, b, dem, a[maxn][maxn];

int calc1 (int x1, int y1, int x2, int y2) {
    return F[x2][y2] - F[x1-1][y2] - F[x2][y1-1] + F[x1-1][y1-1];
}

int calc2 (int x1, int y1, int x2, int y2) {
    return T[x2][y2] - T[x1-1][y2] - T[x2][y1-1] + T[x1-1][y1-1];
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> m >> n >> p >> q;
    cin >> b;
    int med = (p * q + 1) / 2;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            F[i][j] = F[i-1][j]+F[i][j-1]-F[i-1][j-1] + (a[i][j] < b);
            T[i][j] = T[i-1][j]+T[i][j-1]-T[i-1][j-1] + (a[i][j] == b);
        }
    for(int i = 1; i <= m - p + 1; i++)
        for(int j = 1; j <= n - q + 1; j++) {
            int x2 = i + p - 1;
            int y2 = j + q - 1;
            int nho = calc1(i, j, x2, y2);
            int bang = calc2(i, j, x2, y2);
            if(bang > 0 && nho < med && nho + bang >= med)
                dem++;
        }
    cout << dem;
}
