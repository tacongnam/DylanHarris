///....DH....///
#include <bits/stdc++.h>
#define task "ANALYSE"
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

const long long mod = 1e9 + 7;
const int maxn = 200005;

int n, t;
long long res;
map <int, long long> mapp;

long long power(long long a, int b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    long long x = power(a, b / 2);
    if(b % 2 == 0)
        return (x * x) % mod;
    else
        return ((x * x) % mod * a) % mod;
}

int ptich(int id) {
    if(mapp[id] != 0)
        return mapp[id];
    long long x = power(2, id - 1), f = 0;
    For(i, 1, id - 1, 1) {
        if(id % i == 0)
            f += ptich(i);
    }
    mapp[id] = x - f;
    return x - f;
}

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    inp(t);
    mapp[1] = 1;
    while(t--) {
        inp(n);
        outln(ptich(n));
    }
}
