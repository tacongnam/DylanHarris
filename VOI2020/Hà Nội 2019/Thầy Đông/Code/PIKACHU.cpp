///....DH....///
#include <bits/stdc++.h>
#define task                "PIKACHU"
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
/** size of array **/       const int maxn = 1005;

int a[maxn][maxn], m, n, vi[maxn][maxn];
vector < pii > d[maxn];

int dist(int val, int r, int c, int lev, int mov, int turn, int lim) {
    /// mov = 1 (up), 2 (down), 3 (left), 4 (right)
    if(vi[r][c] == 1)
        return INT_MAX;
    vi[r][c] = 1;
    if(turn >= lim)
        return INT_MAX;
    int MIN = INT_MAX;
    if(mov != 2 && r > 0 && (a[r - 1][c] == val || a[r - 1][c] == 0))
        Min(MIN, dist(val, r - 1, c, lev + 1, 1, turn + ((mov == 3 || mov == 4) ? 1 : 0), MIN));

    if(mov != 1 && r <= m && (a[r + 1][c] == val || a[r + 1][c] == 0))
        Min(MIN, dist(val, r + 1, c, lev + 1, 2, turn + ((mov == 3 || mov == 4) ? 1 : 0), MIN));

    if(mov != 4 && c > 0 && (a[r][c - 1] == val || a[r][c - 1] == 0))
        Min(MIN, dist(val, r, c - 1, lev + 1, 3, turn + ((mov == 1 || mov == 2) ? 1 : 0), MIN));

    if(mov != 3 && c <= n && (a[r][c + 1] == val || a[r][c + 1] == 0))
        Min(MIN, dist(val, r, c + 1, lev + 1, 4, turn + ((mov == 1 || mov == 2) ? 1 : 0), MIN));

    vi[r][c] = 0;
    return MIN;
}

priority_queue < pii > pq;
int dd[maxn], t;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            d[a[i][j]].push_back(mp(i, j));
        }
    for(int i = 1; i <= 1000; i++) {
        if(d[i].size() > 0) {
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= n; k++)
                    vi[j][k] = 0;
            dd[i] = dist(i, d[i][1].first, d[i][1].second, 0, 0, 0, INT_MAX);
            pq.push(mp(-dd[i], i));
        }
    }
    while(pq.size() > 0) {
        pii top = pq.top();
        top.ft = -top.ft;
        pq.pop();
        Max(t, top.ft);
        dd[top.sd] = 0;
        a[d[top.sd][0].ft][d[top.sd][0].sd] = 0;
        a[d[top.sd][1].ft][d[top.sd][1].sd] = 0;
        d[top.sd].clear();
        while(pq.size() > 0) {
            pii o = pq.top();
            o.ft = -o.ft;
            if(dd[o.sd] != o.ft)
                pq.pop();
            else
                break;
        }
        for(int i = 1; i <= 1000; i++) {
            if(d[i].size() > 0) {
                for(int j = 1; j <= m; j++)
                    for(int k = 1; k <= n; k++)
                        vi[j][k] = 0;
                dd[i] = dist(i, d[i][1].first, d[i][1].second, 0, 0, 0, INT_MAX);
                pq.push(mp(-dd[i], i));
            }
        }
    }
    cout << t + 1;
}
