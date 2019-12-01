///....DH....///
#include <bits/stdc++.h>
#define task                "COLOR3"
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

int vi[maxn], news[maxn], old[maxn], n, m, can[maxn][4];
vector <int> g[maxn];
string s;

char cc[28], cc1[4];

void solve() {
    for(int i = 2; i <= n; i++)
        if(news[i] == 0) {
            bool ok = false;
            for(int j = 1; j <= 3; j++) {
                if(j != old[i]) {
                    news[i] = j;
                    for(int k = 0; k < g[i].size(); k++) {
                        if(news[i] == news[g[i][k]])
                            break;
                        else if(k == g[i].size()) {
                            ok = true;
                            break;
                        }
                    }
                    if(ok == true)
                        break;
                }
            }
            if(ok == false)
                return;
        }
    for(int i = 1; i <= n; i++)
        cout << cc1[news[i]];
    exit(0);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cc['R' - 'A'] = 1, cc1[1] = 'R';
    cc['G' - 'A'] = 2, cc1[2] = 'G';
    cc['B' - 'A'] = 3, cc1[3] = 'B';
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        old[i + 1] = cc[s[i] - 'A'];
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    if(old[1] != 1) {
        memset(news, 0, sizeof(news));
        news[1] = 1;
        solve();
    }
    if(old[1] != 2) {
        memset(news, 0, sizeof(news));
        news[1] = 2;
        solve();
    }
    if(old[1] != 3) {
        memset(news, 0, sizeof(news));
        news[1] = 3;
        solve();
    }
}
