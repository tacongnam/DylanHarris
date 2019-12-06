///....DH....///
#include <bits/stdc++.h>
#define task "CR"
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
int m, n, u, x, y, z;
long long dp[105][5005][105][3];

long long digit(int id, int sum, int st, int ri, int tight) {
    if(id == m + n + 1)
        return (sum <= u);
    if(sum > u)
        return 0;
    if(dp[ri][sum][st][tight] > -1)
        return dp[ri][sum][st][tight];
    long long a = 0, b = 0;
    if(id == 1) {
        if(st < m)
            a = digit(id + 1, sum, st + 1, ri, 1);
        if(ri < n)
            b = digit(id + 1, sum, st, ri + 1, 2);
        dp[ri][sum][st][tight] = a + b;
    }
    else {
        if(tight == 1) {
            if(st < m)
                a = digit(id + 1, sum + x, st + 1, ri, 1);
            if(ri < n)
                b = digit(id + 1, sum + z * abs(ri + 1 - st), st, ri + 1, 2);
            dp[ri][sum][st][tight] = a + b;
        }
        else {
            if(st < m)
                a = digit(id + 1, sum + z * abs(st + 1 - ri), st + 1, ri, 1);
            if(ri < n)
                b = digit(id + 1, sum + y, st, ri + 1, 2);
            dp[ri][sum][st][tight] = a + b;
        }
    }
    return dp[ri][sum][st][tight];
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> m >> n >> u >> x >> y >> z;
    for(int i = 0; i <= n + 2; i++)
        for(int j = 0; j <= u + 2; j++)
            for(int k = 0; k <= m + 2; k++)
                for(int l = 0; l <= 2; l++)
                    dp[i][j][k][l] = -1;
    cout << digit(1, 0, 0, 0, 0);
}
