///....DH....///
#include <bits/stdc++.h>
#define task "MINIMUM"
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
const int maxn = 1000005;
int n, a[maxn], st[maxn], k;

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    inp(n), inp(k);
    For(i, 1, n, 1)
        inp(a[i]);
    int le = 1, ri = 0;
    For(i, 1, k, 1) {
        while(ri >= le && i - st[le] >= k)
            le++;
        while(ri >= le && a[st[ri]] >= a[i])
            ri--;
        st[++ri] = i;
    }
    outln(a[st[le]]);
    For(i, k + 1, n, 1) {
        while(ri >= le && i - st[le] >= k)
            le++;
        while(ri >= le && a[st[ri]] >= a[i])
            ri--;
        st[++ri] = i;
        outln(a[st[le]]);
    }
}
