///....DH....///
#include <bits/stdc++.h>
#define task ""
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
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

main() {
    cin >> n;
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].ft >> a[i].sd;
        deg[a[i].ft]++, deg[a[i].sd]++;
    }
    for(int i = n; i >= 1; i--) {
        cin >>
    }
}
