///....DH....///
#include <bits/stdc++.h>
#define task                "PPALIN"
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
/** PI **/                  const double M_PI = 3.14159265358979323846;

int d[3][30], maxc, maxl, k, res;
string s;

void add(char c, int p) {
    d[p][c - 'a']++;
    maxc = 0;
    for(int i = 0; i < 26; i++)
        Max(maxc, d[0][i]);
    maxl = 0;
    for(int i = 0; i < 26; i++)
        Max(maxl, d[1][i]);
}

void remov(char c, int p) {
    d[p][c - 'a']--;
    maxc = 0;
    for(int i = 0; i < 26; i++)
        Max(maxc, d[0][i]);
    maxl = 0;
    for(int i = 0; i < 26; i++)
        Max(maxl, d[1][i]);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> s;
    cin >> k;
    int i = 0, j = 0;
    add(s[j], 0);
    while(i < s.size() && j < s.size()) {
        if((j - i + 1 - maxc - maxl) <= k)
            Max(res, j - i + 1);
        if((j - i + 1 - maxc - maxl) <= k && j != s.size() - 1) {
            j++;
            add(s[j], (j % 2 == 1));
        }
        else if((j - i + 1 - maxc - maxl) > k || j == s.size() - 1)
            remov(s[i], (i % 2 == 1)), i++;
    }
    cout << res;
}
