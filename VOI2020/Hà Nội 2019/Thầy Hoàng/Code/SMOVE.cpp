///....DH....///
#include <bits/stdc++.h>
#define task "SMOVE"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
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

const int mod = 1e9 + 7;
const int maxn = 200005;

struct point {
    double x, y;
};

double twoarea(point a, point b, point c) {
    return (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
}

double dist(point a, point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

point a, b, m, n;

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> m.x >> m.y;
    cin >> n.x >> n.y;
    //M, N so voi AB
    double amb = twoarea(a, m, b);
    double anb = twoarea(a, n, b);
    //A, B so voi MN
    double man = twoarea(m, a, n);
    double mbn = twoarea(m, b, n);
    if(amb * anb < 0 && man * mbn < 0) {
        //Cat:
        double maan = dist(m, a) + dist(a, n);
        double mbbn = dist(m, b) + dist(b, n);
        printf("%.4f", min(maan, mbbn));
    }
    else {
        double mn = dist(m, n);
        printf("%.4f", mn);
    }
}
