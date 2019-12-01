/** Note
 - Để int vẫn qua (test hơi yếu -_-)
 - Đừng for(k : j -> min(j + 49, n)), sẽ bị WA, cứ for(k : j -> n) -  -
                                                                    //
**/

/**....DH....**/

#include <bits/stdc++.h>
#define task                "WORDS"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, long long>
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
/** size of array **/       const int maxn = 105;

vector < pii > vt;
int a[maxn][maxn], m, n, res;
string s;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif // ONLINE_JUDGE
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> s;
        long long k = 0;
        for(int j = 0; j < s.size(); j++)
            k = k * 2 + (s[j] - '0');
        vt.pb(mp(s.size(), k));
    }
    sort(vt.begin(), vt.end());
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            long long Hash = 0;
            for(int k = j; k <= n; k++) {
                Hash = Hash * 2 + a[i][k];
                int it = lower_bound(vt.begin(), vt.end(), mp(k - j + 1, Hash)) - vt.begin();
                if(it != vt.size() && vt[it].ft == k - j + 1 && vt[it].sd == Hash)
                    res++;
            }
        }
    cout << res;
}
