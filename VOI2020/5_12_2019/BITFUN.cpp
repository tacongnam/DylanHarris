///....DH....///
#include <bits/stdc++.h>
#define task "BITFUN"
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
const int maxn = 265000;
int t, n, m, F[maxn], s[40], maxx;

void sub4(int in) {

}

bool sub1() {
    return false;
}

main() {
    fi(task".inp");
    fo(task".out");
    cin >> t;
    while(t--) {
        cin >> n;
        int tobit = log2(n) + 1;
        for(int i = maxx; i <= n; i++) {
            /// Tách các bit ra:
            for(int j = 0; j < tobit; j++)
                s[j] = (i >> j) & 1;
            for(int j = 0; j < tobit; j++) {
                if(s[j] == 1) {
                    for(int k = j - 1; k >= 0; k--)
                        if(s[k] == 0) {
                            /// Đổi bit thứ j, k cho nhau
                            int newt = i - (1 << j) + (1 << k);
                            F[i] = max(F[i], 1 - F[newt]);
                        }
                }
            }
        }
        maxx = max(maxx, n);
        if(F[n] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
