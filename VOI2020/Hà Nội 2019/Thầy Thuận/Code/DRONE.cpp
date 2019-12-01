/**
Test9: In ra -1
**/

///....DH....///
#include <bits/stdc++.h>
#define task                "DRONE"
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
/** size of array **/       const int maxn = 30005;

int n, k, a[maxn], c[maxn], st[305][4 * maxn], res, F[maxn][305];

void upd(int id, int l, int r, int pos, int val, int no) {
    if(pos < l || r < pos)
        return ;
    if(l == r) {
        st[no][id] = val;
        return ;
    }
    upd(id * 2, l, (l+r)/2, pos, val, no);
    upd(id*2+1, (l+r)/2+1, r, pos, val, no);
    st[no][id] = max(st[no][2*id], st[no][2*id+1]);
}

int get(int id, int l, int r, int u, int v, int no) {
    if(r < u || v < l)
        return INT_MIN;
    if(u <= l && r <= v)
        return st[no][id];
    return max(get(id*2, l, (l+r)/2, u, v, no), get(id*2+1, (l+r)/2+1, r, u, v, no));
}

//F[i][k] = max(F[j: i + 1 -> i + a[i]][k + 1]) + c[i]
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    fi(task".inp");
//    fo(task".out");
//#endif
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    k++;
    res = -1;
    F[n][1] = c[n];
    upd(1, 1, n, n, F[n][1], 1);
    if(n == 1)
        res = F[n][1];
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= min(k, n - i + 1); j++) {
            if(j == 1 && i != n)
                F[i][j] = -1;
            else {
                F[i][j] = get(1, 1, n, i + 1, min(i + a[i], n), j - 1);
                if(F[i][j] >= 0)
                    F[i][j] += c[i];
            }
            upd(1, 1, n, i, F[i][j], j);
            if(i == 1)
                res = max(res, F[i][j]);
        }
    }
    cout << res;
}
