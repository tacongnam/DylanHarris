///....DH....///
#include <bits/stdc++.h>
#define task                "ANT"
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

int
void sub2() {
    for(int i = 1; i <= 2003; i++) {
        if(i == 1 || i == 2003) {
            int x = s - d[1][i];
            if(x > 0)
                res += (x * (x + 1) / 2) + x;
            x = s - d[2003][i];
            if(x < 0)
                res += (x * (x + 1) / 2) + x;
        }
        else {
            res += ((s - d[1][i]) >= 0) ? (s - d[1][i]) : 0;
            res += ((s - d[2003][i]) >= 0) ? (s - d[2003][i]) : 0;
        }
    }

    for(int i = 2; i <= 2002; i++) {
        res += ((s - d[i][1]) >= 0) ? (s - d[i][2003]) : 0;
        res += ((s - d[i][2003]) >= 0) ? (s - d[i][2003]) : 0;
    }
}

void bfs() {
    for(int i = 0; i <= 2003; i++)
        for(int j = 0; j <= 2003; j++)
            d[i][j] = INT_MAX - 3;
    pos[0] = {1, 0}, pos[1] = {0, 1}, pos[2] = {-1, 0}, pos[3] = {0, -1};

    queue < pii > qu;
    qu.push(mp(1002, 1002));
    exist[1002][1002] = 1;
    d[1002][1002] = 0;

    while(qu.size() > 0) {
        pii t = qu.front();
        qu.pop();

        if(cnv[t.ft][t.sd] == 1) {
            continue;
        }

        for(int i = 0; i <= 3; i++) {
            Min(d[t.ft][t.sd], d[t.ft + pos[i].ft][t.sd + pos[i].sd] + 1);

            if(exist[t.ft][t.sd] == 0 && t.ft <= 2003 && t.ft > 0 && t.sd <= 2003 && t.sd > 0 && d[t.ft][t.sd] + 1 <= s) {
                qu.push(mp(t.ft + pos[i].ft, t.sd + pos[i].sd));
                exist[t.ft][t.sd] = 1;
            }
        }

    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        cnv[u + 1002][v + 1002] = 1;
    }
    bfs();
    if(s > 1000)
        sub2();
    cout << res;
}
