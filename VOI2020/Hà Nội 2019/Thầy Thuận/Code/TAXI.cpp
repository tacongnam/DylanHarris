///....DH....///
#include <bits/stdc++.h>
#define task                "TAXI"
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
/** size of array **/       const int maxn = 25;
/** PI **/                  const double M_PI = 3.14159265358979323846;

int n, c[maxn][maxn], res;

/*
QHD trạng thái (dpt: (2n)^2 . 2 ^ (2n))

TSP (i, s) : Hành trình MIN mà người du lịch đã đi qua mọi thành phố trong tập S và đang tới thành phố i

TSP (i, s) = min ( TSP (j, s - {j} ) + C [i, j])  với mọi j thuộc S
*/

bool getbit(int x, int i) {
    return ((x >> i) & 1);
}
void solve() {
    for(int s = 1; s < (1 << (n + 1)); s++) {
        vector <int> bit[3];
        for(int i = 0; i < n; i++)
            bit[getbit(s, i)].pb(i);
        for(int i = 0; i < bit[0].size(); i++)
            for(int j = 0; j < bit[1].size(); j++)
                Min(TSP[bit[0][i]][s], TSP[bit[1][j]][s - (1 << (bit[1][j] - 1))] + c[bit[1][j]][bit[0][i]]);
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> n;
    n /= 2;
    for(int i = 1; i <= 2 * n + 1; i++)
        for(int j = 1; j <= 2 * n + 1; j++)
            cin >> c[i][j];
    res = INT_MAX;
    dequy(1, 0, 0, 0);
    cout << res;
}
