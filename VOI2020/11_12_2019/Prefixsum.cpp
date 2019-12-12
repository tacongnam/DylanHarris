///....DH....///
#include <bits/stdc++.h>
#define task "PREFIXSUM"
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

int n;
long long a[maxn], k;

bool solve(long long row) {
    double com = 1, sum = 0, c, r;
    for(int i = n; i >= 1; i--) {
        sum += double(a[i]) * com;
        if(sum >= k)
            return true;
        r = double(row + n - i);
        c = double(r - row + 1);
        com = com * r / c;
        if(com > k)
            com = k;
    }
    return false;
}

main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0 && i == 1)
            i--, n--;
    }
    long long l = 0, r = k;
    while(l < r) {
        long long tb = (l + r) / 2;
        if(solve(tb) == true)
            r = tb;
        else
            l = tb + 1;
    }
    cout << l;
}
