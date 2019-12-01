/**
- Thuật toán sử dụng: QHĐ đảo nhãn
- F[i, k] là vị trí xâu b nhỏ nhất thoả mãn dãy con chung có k phần tử, kết thúc tại a[i]

**/

///....DH....///
#include <bits/stdc++.h>
#define task                "LCS"
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
    if(a == 0 || a > b)
        a = b;
}

template <typename R, typename D> inline void Max(R &a, D b) {
    if(a < b)
        a = b;
}
/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 1000005;
/** PI **/                  const double M_PI = 3.14159265358979323846;

int n, m, a[1005], b[maxn], res, F[1005][1005], pos;
vector <int> v[2 * maxn];
vector <int> ans;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i], a[i] += 1000000;
    for(int i = 1; i <= n; i++) {
        cin >> b[i], b[i] += 1000000;
        v[b[i]].pb(i);
    }

    ///------------------------------

    for(int i = 1; i <= m; i++)
        for(int k = 1; k <= i; k++) {
            int val = (F[i-1][k-1] == 0 && k > 1) ? (n + 1) : (F[i-1][k-1] + 1);
            int t = lower_bound(v[a[i]].begin(), v[a[i]].end(), val) - v[a[i]].begin();
            F[i][k] = F[i - 1][k];
            if(t != v[a[i]].size())
                Min(F[i][k], v[a[i]][t]);
            if(F[i][k] != F[i - 1][k]) {
                if(res < k)
                    res = k, pos = i;
            }
            //cerr << "i: " << i << ", k: " << k << ", F[i][k]: " << F[i][k] << "\n";
        }
    for(int i = pos; i >= 1; i--) {
        if(a[i] == b[F[i][res]]) {
            ans.pb(a[i] - 1000000);
            res--;
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}
