///....DH....///
#include <bits/stdc++.h>
#define task                "793C"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pdd                 pair<double, double>
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
                            const long double eps = 0.00000001;

struct edge {
    int x0, vx;  /// y = vx (velocity) . t (time) + x0 (initial pos) (x)
    int y0, vy;  /// y = vy (velocity) . t (time) + y0 (initial pos) (y)
};

struct trap {                   ///  y    x1                 x2
    int x1, y1;                 ///  |  y1 |-------------------|
    int x2, y2;                 ///  |  y2 |-------------------|
} t;                            ///  ------|-------------------|--- x

edge mice[maxn];
int n;
double MAX = -INT_MIN, MIN = INT_MAX;

pdd check(edge e) {
    double stx = -INT_MAX, finx = INT_MAX, sty = -INT_MAX, finy = INT_MAX;
    if(e.vx != 0) {
        stx = double(t.x1 - e.x0) / double(e.vx);
        finx = double(t.x2 - e.x0) / double(e.vx);
        if(stx < 0)
            return mp(-1, -1);
        if(finx < 0)
            finx = stx;
    }
    if(e.vy != 0) {
        sty = double(t.y1 - e.y0) / double(e.vy);
        finy = double(t.y2 - e.y0) / double(e.vy);
        if(sty < 0)
            return mp(-1, -1);
        if(finy < 0)
            finy = sty;
    }
    if(finx <= sty)
        return mp(-1, -1);
    return mp(max(stx, sty), min(finx, finy));
}

bool checkbefore(edge e) {
    if(e.vx == 0 && e.vy == 0) {
        if(e.x0 <= t.x1 || e.x0 >= t.x2)
            return false;
        if(e.y0 <= t.y1 || e.y0 >= t.y2)
            return false;
    }
    if(e.vx == 0)
        if(e.y0 <= t.y1 || e.y0 >= t.y2)
            return false;
    if(e.vy == 0)
        if(e.x0 <= t.x1 || e.x0 >= t.x2)
            return false;
    return true;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    for(int i = 1; i <= n; i++) {
        cin >> mice[i].x0 >> mice[i].y0 >> mice[i].vx >> mice[i].vy;
        if(checkbefore(mice[i]) == false) {
            cout << "-1";
            return 0;
        }
        pdd lim = check(mice[i]);
        Min(MIN, lim.sd);
        Max(MAX, lim.ft);
    }
    if(MIN > MAX)
        cout << setprecision(10) << MAX;
    else
        cout << "-1";
    return 0;
}
