///....DH....///
#include <bits/stdc++.h>
#define task "SOLPIN"
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
const int maxn = 1205;

int m, n, id, q;
long long F[maxn][maxn], a[maxn][maxn];
int row[maxn], col[maxn];

void red(int &x, int u) {
    x %= u;
    if(x == 0)
        x = u;
}

long long calc(int x1, int y1, int x2, int y2) {
    red(x1, m), red(x2, m), red(y1, n), red(y2, n);
    if(x2 < x1)
        x2 += m;
    if(y2 < y1)
        y2 += n;
    return F[x2][y2] - F[x1 - 1][y2] - F[x2][y1 - 1] + F[x1 - 1][y1 - 1];
}

void inp_constr() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i + m][j] = a[i][j];
            a[i][j + n] = a[i][j];
            a[i + m][j + n] = a[i][j];
        }
    for(int i = 1; i <= 2 * m ; i++)
        for(int j = 1; j <= 2 * n; j++)
            F[i][j] = F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1] + a[i][j];
//    cout << "a[i][j]\n";
//    for(int i = 1; i <= 2 * m; i++) {
//        for(int j = 1; j <= 2 * n; j++)
//            cout << a[i][j] << " ";
//        cout << "\n";
//    }

}

void query() {
    int dx = 1, dy = 1;
    cin >> q;
    while(q--) {
        cin >> id;
        if(id == 0) {
            int d, r;
            cin >> d >> r;
            dx += d, dy += r;
            red(dx, n), red(dy, m);
        }
        else if(id == 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << calc(dy + x1 - 1, dx + y1 - 1, dy + x2 - 1, dx + y2 - 1) << "\n";
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    inp_constr();
    query();
}
