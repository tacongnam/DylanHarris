///....DH....///
#include <bits/stdc++.h>
#define task                ""
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

int n, ans[maxn];
multiset <int> st;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    for(int i = 1; i <= n; i++) {
        __typeof(st.begin()) it = st.end();
        it--;
        ans[i] = *it;
        st.erase(it);
        for(int j = 1; j < i; j++) {
            __typeof(st.begin()) it1 = st.find(__gcd(ans[i], ans[j]));
            st.erase(it1);
            it1 = st.find(__gcd(ans[i], ans[j]));
            st.erase(it1);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
