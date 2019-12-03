/** Note
 - Không đặt số Pi là 1 biến, sử dụng acos(-1) hoặc các hàm lượng giác tương tự
 - Sử dụng kiểu dữ liệu long double (để tăng độ chính xác cho các chữ số)
**/

/**....DH....**/

#include <bits/stdc++.h>
#define task                "CollidingCircles"
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

long long n, k, r[maxn], s[maxn];
long double res, c2n[maxn];

void C2n() {
    For(i, 2, n, 1)
    c2n[i] = ((long double)(i) * (i - 1)) / 2;
}

long double prob() {
    long double P = 0, pre = 1;
    Ford(i, n, n - k + 1, 1) {
        P += pre * ((long double)(1) / c2n[i]);
        pre *= ((c2n[i] - 1) / c2n[i]);
    }
    return P;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif
    cin >> n >> k;
    For(i, 1, n, 1)
    cin >> r[i];
    C2n();
    long double P = prob();
    Ford(i, n, 1, 1)
        s[i] = s[i + 1] + r[i];
    For(i, 1, n - 1, 1)
        res += (long double)(r[i]) * s[i + 1];
    res *= 2 * P;
    For(i, 1, n, 1)
        res += (long double)(r[i]) * r[i];
    printf("%.10lf", res * acosl(-1));
}
