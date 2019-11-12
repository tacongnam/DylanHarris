///....DH....///
#include <bits/stdc++.h>
#define task "BEAULC"
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

template <typename T> inline bool inp(T &x) {
    x = 0; /// Reset x
    char c = getchar();
    bool neg = false, nex = false;
    while(c < '0' || '9' < c && c != '-')
        c = getchar();
    if(c == '-')
        neg = true;
    while('0' <= c && c <= '9')
        x = x * 10 + (c - '0'), c = getchar(), nex = true;
    if(neg == true)
        x = -x;
    return nex;
}

template <typename T> inline bool inpstr(T &x) {
    char c = getchar();
    bool nex = false;
    while(c <= 32 || c > 126)
        c = getchar();
    while(32 < c && c <= 126)
        x += c, c = getchar(), nex = true;
    return nex;
}

template <typename T> inline void out(T x) { ///use for long long, int
    if(x > 9)
        out(x / 10);
    putchar(x % 10 + 48);
}

template <typename T> inline void outln(T x) {
    out(x);
    putchar('\n');
}

template <typename T> inline void outsp(T x) {
    out(x);
    putchar(' ');
}

template <typename L, typename R> inline void Max(L &x, R y) {
    if(y > x)
        x = y;
}

template <typename L, typename R> inline void Min(L &x, R y) {
    if(x > y)
        x = y;
}

const int mod = 1e9 + 7;
const int maxn = 200005;
int loga[maxn], p[18][15][maxn], d[15][maxn], pr[maxn], L[maxn], F[maxn], res, n, k;
vector <int> v[maxn];
string s[15];

int get(int l, int r, int row) {
    int lo = loga[r - l + 1], ans = INT_MAX;
    Min(ans, p[lo][row][l]);
    Min(ans, p[lo][row][r - (1 << lo) + 1]);
    return ans;
}

int binary(int row, int lim) {
    int l = 0, r = lim;
    while(l < r) {
        int tb = (l + r) / 2;
        if(get(tb, lim, row) < d[row][lim])
            l = tb + 1;
        else
            r = tb;
    }
    return l;
}

void make_vector() {
    For(i, 1, k, 1)
        v[0].pb(0);
    For(i, 1, k, 1)
        For(j, 1, n, 1) {
            if(s[i][j - 1] == '(')
                d[i][j] = d[i][j - 1] + 1;
            else if(s[i][j - 1] == ')')
                d[i][j] = d[i][j - 1] - 1;
            v[j].pb(d[i][j]);
        }
}

void make_pr() {
    For(i, 1, k, 1) {
        For(j, 0, n, 1)
            p[0][i][j] = d[i][j];
        For(l, 1, 16, 1)
            For(j, 0, n, 1) {
                p[l][i][j] = INT_MAX;
                Min(p[l][i][j], p[l - 1][i][j]);
                Min(p[l][i][j], p[l - 1][i][j + (1 << (l - 1))]);
            }
    }
    For(i, 0, n + 2, 1)
        loga[i] = log2(i);
    For(j, 1, n, 1)
        For(i, 1, k, 1)
            Max(pr[j], binary(i, j));
}

map < vector <int>, int> mapp;
void make_l() {

    mapp[v[0]] = 0;
    For(i, 1, n, 1) {
        if(mapp.find(v[i]) != mapp.end())
            L[i] = mapp[v[i]];
        else
            L[i] = -1;
        mapp[v[i]] = i;
    }
}

void make_ans() {
    For(i, 1, n, 1) {
        if(L[i] >= pr[i])
            F[i] = F[L[i]] + 1;
        else
            F[i] = 0;
        res += F[i];
    }
}

main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    inp(k), inp(n);
    For(i, 1, k, 1)
        inpstr(s[i]);
    make_vector();
    make_pr();
    make_l();
    make_ans();
    out(res);
}
