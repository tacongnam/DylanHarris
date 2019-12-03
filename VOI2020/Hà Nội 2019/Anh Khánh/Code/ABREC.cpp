///....DH....///
#include <bits/stdc++.h>
#define task "ABREC"
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
int n, m, a[maxn], b[maxn], F[maxn], t, k, d[maxn], dem[maxn], res;

int in(int i, int j) {
    return (i - 1) * (n + 1) + j;
}

void change() {
    if(n < m) {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                b[(j - 1) * (m + 1) + i] = a[in(i, j)];
        swap(m, n);
    }
    else {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                b[in(i, j)] = a[in(i, j)];
    }
}

void calcsum() {
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            F[in(i, j)] = F[in(i-1, j)] + F[in(i, j-1)] - F[in(i-1, j-1)] + b[in(i, j)];
}

int calc(int x1, int y1, int x2, int y2) {
    return F[in(x2, y2)] - F[in(x1-1, y2)] - F[in(x2, y1-1)] + F[in(x1-1,y1-1)];
}

void solve() {
    res = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++) {
            vector < pii > v;
            v.pb(mp(0, 0));
            for(int x = 1; x <= n; x++)
                v.pb(mp(calc(i, 1, j, x), x));
            sort(v.begin(), v.end());
            deque < pii > dq;
            for(int x = 0; x <= n; x++) {
                while(dq.size() > 0 && abs(v[x].ft - dq.front().ft) > k)
                    dq.pop_front();
                while(dq.size() > 0 && v[x].sd < dq.back().sd)
                    dq.pop_back();
                if(dq.size() > 0)
                    Max(res, (j - i + 1) * abs(v[x].sd - dq.front().sd));
                dq.pb(v[x]);
            }

            dq.clear();
            for(int x = 0; x <= n; x++) {
                while(dq.size() > 0 && abs(v[x].ft - dq.front().ft) > k)
                    dq.pop_front();
                while(dq.size() > 0 && v[x].sd > dq.back().sd)
                    dq.pop_back();
                if(dq.size() > 0)
                    Max(res, (j - i + 1) * abs(v[x].sd - dq.front().sd));
                dq.pb(v[x]);
            }
        }
    cout << res << "\n";
}

string s;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        for(int i = 1; i <= m; i++) {
            cin >> s;
            for(int j = 0; j < n; j++)
                if(s[j] == 'A')
                    a[in(i, j + 1)] = 1;
                else
                    a[in(i, j + 1)] = -1;
        }
        change();
        calcsum();
        solve();
//        for(int i = 1; i <= m; i++) {
//            for(int j = 1; j <= n; j++)
//                cout << F[in(i, j)] << " ";
//            cout << "\n";
//        }
    }
}
