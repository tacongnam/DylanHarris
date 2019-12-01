///....DH....///
#include <bits/stdc++.h>
#define task                "COLOR"
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
/** size of array **/       const int maxn = 510;

int c[maxn], e[maxn][maxn], n, m, u, v, vi[maxn];
queue < pii > pq;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
//    string s1 = "", s2 = "";
//    cin >> s1 >> s2;
//    for(int i = 0; i < s1.size(); i++) {
//        if(s1[i] == 'R' && s2[i] == 'G')
//            continue;
//        if(s1[i] == 'G' && s2[i] == 'R')
//            continue;
//        if(s1[i] == 'B' && s2[i] == 'B')
//            continue;
//        cerr << "ERROR at element " << i + 1 << "\n";
//    }
    cin >> n >> m;
    if(m > 0) {
        cin >> u >> v;
        pq.push(mp(u, v));
        c[u] = 1, c[v] = 2;
        e[u][v] = e[v][u] = 1;
    }
    for(int i = 2; i <= m; i++) {
        cin >> u >> v;
        e[u][v] = e[v][u] = 1;
    }
    while(pq.size() > 0) {
        pii p = pq.front();
        pq.pop();
        u = p.ft, v = p.sd;
        if(u < v)
            swap(u, v);
        vi[u] = 1, vi[v] = 1;
        for(int i = 1; i <= n; i++) {
            if(e[u][i] == 1 && e[v][i] == 1) {
                if(c[i] == 0) {
                    for(int j = 1; j <= 3; j++)
                        if(j != c[u] && j != c[v])
                            c[i] = j;
                    pq.push(mp(u, i));
                    pq.push(mp(v, i));
                } else {
                    if(c[i] == c[u] || c[i] == c[v]) {
                        cout << "NO";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        if(c[i] == 1)
            cout << "R";
        else if(c[i] == 2)
            cout << "G";
        else
            cout << "B";
    }
}
