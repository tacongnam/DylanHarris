///....DH....///
#include <bits/stdc++.h>
#define task "FROG"
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

template <typename T> inline bool inp(T &x) {
    x = 0; /// Reset x
    char c = getchar();
    bool neg = false, nex = false;
    while(c < '0' || '9' < c && c != '-')
        c = getchar();
    if(c == '-')
        neg = true;
    while('0' <= c && c <= '9')
        x = x * 10 + (c - '0'), c = getchar(), nex = true;
    if(neg == true)
        x = -x;
    return nex;
}

template <typename T> inline void out(T x) { ///use for long long, int
    if(x > 9)
        out(x / 10);
    putchar(x % 10 + 48);
}

template <typename T> inline void outln(T x) {
    out(x);
    putchar('\n');
}

template <typename T> inline void outsp(T x) {
    out(x);
    putchar(' ');
}

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
int n, st[maxn], F[maxn][maxn], k, m, pos;
long long res, dp[maxn][maxn], a[maxn][maxn];
vector <int> ans;

void upd(int id) {
    int le = 1, ri = 0;
    For(j, 1, n + k, 1) {
        while(ri >= le && j - st[le] > 2 * k)
            le++;
        while(ri >= le && dp[id][st[ri]] <= dp[id][j])
            ri--;
        st[++ri] = j;
        F[id][j] = st[le];
    }
//    For(i, 1, m, 1) {
//        For(j, 1, n + k, 1)
//            outsp(F[i][j]);
//        cout << '\n';
//    }
}

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    inp(m), inp(n), inp(k);
    For(i, 1, m, 1)
    For(j, 1, n, 1)
    inp(a[i][j]);
//    cout << '\n';
    For(i, 1, m, 1) {
        For(j, 1, n + k, 1)
        dp[i][j] = dp[i - 1][F[i - 1][j + k]] + a[i][j];
        upd(i);
    }
    For(i, 1, n + k, 1) {
        if(res < dp[m][i]) {
            res = dp[m][i];
            pos = i;
        }
    }
//    For(i, 1, m, 1) {
//        For(j, 1, n, 1)
//        outsp(dp[i][j]);
//        cout << '\n';
//    }
//    cout << '\n';
    outln(res);
    int line = m;
    while(line > 0) {
        ans.pb(pos);
        pos = F[line - 1][pos + k];
        line--;
    }
    Ford(i, ans.size() - 1, 0, 1)
        outln(ans[i]);
}
