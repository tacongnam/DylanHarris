///....DH....///
#include <bits/stdc++.h>
#define task "STRING"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pli pair<long long, int>
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

const long long mod = 1e9 + 7;
const long long maxn = 200005;

long long h[maxn], po[maxn];
string t;
int q, id, dempo, cnt;
vector < pli > s;

long long get(long long l, long long r) {
    return (h[r] - h[l - 1] * po[r - l + 1] + 20 * mod) % mod;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    po[0] = 1;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> id;
        if(id == 2) {
            cin >> t;
            while(dempo < t.size())
                po[++dempo] = po[dempo - 1] * 29 % mod;
            for(int j = 1; j <= t.size(); j++)
                h[j] = (h[j - 1] * 29 % mod + (t[j - 1] - 'a' + 1)) % mod;
            long long res = 0;
            for(int j = 0; j < s.size(); j++) {
                int dem = 0;
                for(int k = s[j].sd; k <= t.size(); k++)
                    if(get(k - s[j].sd + 1, k) == s[j].ft)
                        dem++;
                res += dem * s[j].sd;
            }
            cout << res << "\n";
        }
        else {
            cin >> t;
            while(dempo < t.size())
                po[++dempo] = po[dempo - 1] * 29 % mod;
            long long res = 0;
            for(int j = 1; j <= t.size(); j++)
                res = (res * 29 % mod + (t[j - 1] - 'a' + 1)) % mod;
            for(int j = 0; j < s.size(); j++)
                if(s[j].ft == res && s[j].sd == (int)t.size())
                    continue;
            s.push_back(mp(res, t.size()));
        }
    }
}
