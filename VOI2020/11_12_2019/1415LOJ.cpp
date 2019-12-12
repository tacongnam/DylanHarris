///....DH....///
#include <bits/stdc++.h>
#define task "1415LOJ"
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

template <typename R, typename D> inline void Min(R &a, D b)
{
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b)
{
    if(a<b)
        a=b;
}

const int mod = 1e9 + 7;
const int maxn = 200005;

struct Node
{
    long long dp, ma, sum;
    bool laz;
    Node operator + (const Node &P)
    {
        return {min(dp, P.dp), ma, min(sum, P.sum)};
    }
} st[4 * maxn];

int b[maxn], maxpos, n, F[maxn], N[maxn], maxval;
long long a[maxn], dp[maxn], maxele[4 * maxn];

void laz(int id)
{
    if(st[id].laz == true)
    {
        Max(st[id * 2].ma, st[id].ma);
        Max(st[id * 2 + 1].ma, st[id].ma);
        st[id * 2].sum = st[id * 2].dp + st[id * 2].ma;
        st[id * 2 + 1].sum = st[id * 2 + 1].dp + st[id * 2 + 1].ma;
        st[id].laz = false;
        st[id * 2].laz = st[id * 2 + 1].laz = true;
    }
    return ;
}

void updmax(int id, int l, int r, int u, int v, long long val)
{
    if(r < u || v < l || u > v)
        return ;
    if(u <= l && r <= v)
    {
        st[id].ma = val;
        st[id].sum = st[id].dp + st[id].ma;
        st[id].laz = 1;
        return ;
    }
    laz(id);
    updmax(id * 2, l, (l + r)/2, u, v, val);
    updmax(id * 2 + 1, (l + r)/2+1, r, u, v, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void upddp(int id, int l, int r, int u, long long val)
{
    if(u < l || r < u)
        return ;
    if(l == r)
    {
        st[id].dp = val;
        st[id].sum = st[id].ma + st[id].dp;
        return ;
    }
    laz(id);
    upddp(id * 2, l, (l + r)/2, u, val);
    upddp(id * 2 + 1, (l + r)/2+1, r, u, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

long long get(int id, int l, int r, int u, int v)
{
    if(u > v)
        return 0;
    if(r < u || v < l || u > v)
        return LLONG_MAX;
    if(u <= l && r <= v)
        return st[id].sum;
    laz(id);
    return min(get(id * 2, l, (l+r)/2, u, v), get(id * 2 + 1, (l+r)/2+1, r, u, v));
}

void updpos(int id, int l, int r, int u, int val)
{
    if(u < l || r < u)
        return ;
    if(l == r)
    {
        maxele[id] = val;
        return ;
    }
    updpos(id * 2, l, (l+r)/2, u, val);
    updpos(id * 2 + 1, (l+r)/2+1, r, u, val);
    maxele[id] = max(maxele[id * 2], maxele[id * 2 + 1]);
}

void make_tree2(int id, int l, int r) {
    maxele[id] = 0;
    if(l == r) {
        N[l] = 0;
        return ;
    }
    make_tree2(id * 2, l, (l + r)/2);
    make_tree2(id * 2 + 1, (l+r)/2+1, r);
}

int getpos(int id, int l, int r, int u, int key)
{
    if(l == r)
        return (maxele[id] > key) ? l : 0;
    if(maxele[id * 2 + 1] > key)
        return getpos(id*2+1, (l+r)/2+1, r, u, key);
    else
        return getpos(id*2, l, (l+r)/2, u, key);
}

void solve(int in)
{
    F[b[in]] = N[b[in]];
    N[b[in]] = in;
    Max(maxpos, F[b[in]]);

    int pre = getpos(1, 0, n, in, a[in]);
    updpos(1, 0, n, in, a[in]);

    updmax(1, 0, n, pre, in - 1, a[in]);

    dp[in] = get(1, 0, n, maxpos, in - 1);

    upddp(1, 0, n, in, dp[in]);
}

int t;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi("SAVETREES.inp");
    fo("SAVETREES.out");
    cin >> t;
    for(int j = 1; j <= t; j++)
    {
        memset(st, 0, sizeof(st));
        memset(N, 0, sizeof(N));
        memset(maxele, 0, sizeof(maxele));
        maxpos = 0, maxval = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> b[i] >> a[i];
        for(int i = 1; i <= n; i++)
            solve(i);
        cout << "Case " << j << ": " << dp[n] << "\n";
    }
}
