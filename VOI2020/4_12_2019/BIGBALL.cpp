///....DH....///
#include <bits/stdc++.h>
#define task "BIGBALL"
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

struct Cor {
    double x, y, z;
    double abso () {
        long double sq =  x * x +  y * y +  z * z;
        return sqrt(sq);
    }
    Cor operator ^ (const Cor &C) {
        Cor prod = { (long double) y*C.z- (long double) C.y*z, (long double) z*C.x- (long double) x*C.z, (long double) x*C.y- (long double) y*C.x};
        return prod;
    }
};

struct Line {
    Cor x, y;
    double dist (const Cor &P) {
        Cor cp = {y.x - x.x, y.y - x.y, y.z - x.z};
        Cor MM0 = {P.x - x.x, P.y - x.y, P.z - x.z};
        Cor product = cp ^ MM0;
        double tu = product.abso();
        double mau = cp.abso();
        return (tu / mau);
    }
} D;

int n;

int getans(double x) {
    int in = x;
    if(in < x)
        return in + 1;
    else
        return in;
}

main() {
    fi(task".inp");
    fo(task".out");
    scanf("%d", &n);
    scanf("%lf%lf%lf%lf%lf%lf", &D.x.x, &D.x.y, &D.x.z, &D.y.x, &D.y.y, &D.y.z);
    for(int i = 1; i <= n; i++) {
        Cor P;
        scanf("%lf%lf%lf", &P.x, &P.y, &P.z);
        printf("%d\n", getans(D.dist(P)));
    }
}
