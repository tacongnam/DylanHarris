///....DH....///
#include <bits/stdc++.h>
#define task                "PLUS"
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

long long a, b, d;
vector <string> res;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif
    cin >> a >> b;
    while(a != b) {
        d = __gcd(a, b);
        a /= d, b /= d;
        if(a % 2 == 1 && b % 2 == 1) {
            long long c = min(a, b);
            if(a < b) {
                res.push_back("B+=A");
                res.push_back("A+=A");
            }
            else {
                res.push_back("A+=B");
                res.push_back("B+=B");
            }
            a += c, b += c;
            continue;
        }
        if(a % 2 == 1 && b % 2 == 0) {
            res.push_back("A+=A");
            a += a;
            continue;
        }
        if(a % 2 == 0 && b % 2 == 1) {
            res.push_back("B+=B");
            b += b;
            continue;
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";
}
