///....DH....///
#include <bits/stdc++.h>
#define task                "WBRACK2"
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

long long n, k, F[250][250][3];

long long calc (int i, int c, bool ok) {
    if (i > 2 * n)
        return (ok == false && c == n);
    if(F[i][c][ok] > -1)
        return F[i][c][ok];
    return F[i][c][ok] = calc (i + 1, c + 1, ok) + calc(i + 1, c, ok & ((i - c) <= c));
}

void truyvet(int i, int c, bool ok) {
    if(i > 2 * n)
        return ;
    if(k <= calc (i + 1, c + 1, ok))
        cout << "(",  truyvet(i + 1, c + 1, ok);
    else {
        k -= calc(i + 1, c + 1, ok);
        cout << ")";
        truyvet(i + 1, c, ok & ((i - c) <= c));
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    memset(F, -1, sizeof(F));
    cin >> n >> k;
    calc(1, 0, 1);
    truyvet(1, 0, 1);
}
