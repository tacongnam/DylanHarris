///....DH....///
#include <bits/stdc++.h>
#define task                "706C"
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
/** size of array **/       const int maxn = 100005;
/** PI **/                  const double M_PI = 3.14159265358979323846;

int cmp(string a, string b) {
    /// 1: a > b, 0: a = b, -1: a < b
    int lim = min(a.size(), b.size());
    for(int i = 0; i < lim; i++) {
        if(a[i] > b[i])
            return 1;
        if(a[i] < b[i])
            return -1;
    }
    if(a.size() == b.size())
        return 0;
    if(a.size() > b.size())
        return 1;
    if(a.size() < b.size())
        return -1;
}

string s[maxn], r[maxn];
int n;
long long c[maxn], dp[3][maxn];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    dp[0][1] = 0, dp[1][1] = c[1];
    for(int i = 2; i <= n; i++) {
        dp[0][i] = dp[1][i] = LLONG_MAX;
        int check = 0;
        ///dp[0][i]:
        if(dp[0][i - 1] != LLONG_MAX && cmp(s[i], s[i - 1]) > -1)
            Min(dp[0][i], dp[0][i - 1]);
        else
            check++;
        if(dp[1][i - 1] != LLONG_MAX && cmp(s[i], r[i - 1]) > -1)
            Min(dp[0][i], dp[1][i - 1]);
        else
            check++;
        ///dp[1][i]:
        if(dp[0][i - 1] != LLONG_MAX && cmp(r[i], s[i - 1]) > -1)
            Min(dp[1][i], dp[0][i - 1] + c[i]);
        else
            check++;
        if(dp[1][i - 1] != LLONG_MAX && cmp(r[i], r[i - 1]) > -1)
            Min(dp[1][i], dp[1][i - 1] + c[i]);
        else
            check++;
        if(check == 4) {
            cout << -1;
            return 0;
        }
    }
    cout << min(dp[0][n], dp[1][n]);
    return 0;
}
