///....DH....///
#include <bits/stdc++.h>
#define task                "TRIPLE"
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

int n, m, a[maxn];
long long dem;

void solve(int id) {
    int l = id + 1, r = n, cnt = 0;
    while(l < r) {
        if(a[l] + a[r] > m - a[id])
            r--;
        else if(a[l] + a[r] < m - a[id])
            l++;
        else {
            int vl = a[l], vr = a[r];
            long long cntl = 0, cntr = 0;
            while(a[l] == vl && l <= n)
                cntl++, l++;
            while(a[r] == vr && r > id)
                cntr++, r--;
            if(vl != vr)
                dem = (dem + cntl * cntr) % mod;
            else
                dem = (dem + cntl * (cntl - 1) / 2) % mod;
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n - 1; i++)
        solve(i);
    cout << dem;
}
