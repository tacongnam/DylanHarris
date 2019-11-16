///....DH....///
#include <bits/stdc++.h>
#define task "UNION"
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
const int maxn = 300005;
long long n, a[maxn], cnt;
deque < long long > st;

void solve() {
    sort(a + 1, a + n + 1, greater<int>());
    a[n + 1] = -2;
    For(i, 1, n + 1, 1) {
        while(a[i] == a[i + 1])
            i++;
        if(st.size() == 0 && i != n + 1) {
            st.push_back(a[i] / 2);
            cnt++;
            continue;
        }
        while(st.size() > 0) {
            if(i == n + 1 && st.front() == st.back())
                break;
            while(st.size() > 1 && st[0] == st[1])
                st.pop_front();
            if(a[i] > st.front()) {
                st.push_back(a[i] / 2);
                cnt++;
                break;
            }
            else if(a[i] == st.front())
                break;
            else {
                st.pb(st.front() / 2);
                cnt++;
                st.pop_front();
            }
        }

    }
    outln(cnt);
}

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    inp(n);
    For(i, 1, n, 1)
        inp(a[i]);
    solve();
}
