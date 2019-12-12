///....DH....///
#include <bits/stdc++.h>
#define task "1120LOJ"
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
    int env[12], len, num, laz;
} st[500005];

struct rec
{
    int x, y1, y2, t;
    bool operator < (const rec &P)
    {
        if(x == P.x)
            return t < P.t;
        return x < P.x;
    }
};

vector <rec> cor;
vector <int> ycor;
int t, n, k;
long long res;
map <int, int> mpp;

void upd(int id, int l, int r, int u, int val)
{
    st[id].len = 0;
    st[id].env = 0;
    if(r < u || u < l)
        return ;
    if(l == r)
    {
        st[id].num = val;
        return ;
    }
    upd(id * 2, l, (l + r) / 2, u, val);
    upd(id * 2 + 1, (l + r) / 2 + 1, r, u, val);
    st[id].num = st[id * 2].num + st[id * 2 + 1].num;
}

void lazy(int id) {

}

void update(int id, int l, int r, int u, int v, int type)
{
    if(r < u || v < l || u > v)
        return ;
    if(u <= l && r <= v)
    {
        for(int i = 1; i <= 10; i++)
            st[id].env[i] += type;
        if(type == 1)
        {
            if(st[id].env[k] > 0)
                st[id].len = st[id].num;
        }
        else if(st[id].env[k - 1] > 0)
        {
            if(l < r)
                st[id].len = st[2 * id].len + st[2 * id + 1].len;
            else
                st[id].len = 0;
        }
        return ;
    }
    update(id * 2, l, (l + r)/2, u, v, type);
    update(id * 2 + 1, (l + r)/2 + 1, r, u, v, type);
    if(st[id].env == 0 && l < r)
        st[id].len = st[2 * id].len + st[2 * id + 1].len;
    return ;
}


void setup()
{
    cor.clear();
    ycor.clear();
    res = 0;
}

void compress()
{
    sort(ycor.begin(), ycor.end());
    int cnt = 1;
    mpp[ycor[0]] = 1;
    for(int i = 1; i < ycor.size(); i++)
    {
        if(ycor[i] != ycor[i - 1]) {
            mpp[ycor[i]] = ++cnt;
            upd(1, 1, 100001, cnt - 1, ycor[i] - ycor[i - 1]);
        }
        else
            mpp[ycor[i]] = cnt;
    }
    return ;
}

long long query()
{
    compress();
    sort(cor.begin(), cor.end());
    cor.pb({cor[0].x, 0, 0, -2});
    sort(cor.begin(), cor.end());
    for(int i = 1; i < cor.size(); i++)
    {
        res += 1ll * st[1].len * (cor[i].x - cor[i - 1].x);
        update(1, 1, 100001, mpp[cor[i].y1], mpp[cor[i].y2 + 1] - 1, cor[i].t);
    }
    return res;
}

main()
{
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> t;
    for(int i = 1; i <= t; i++) {
        setup();
        cin >> n >> k;
        int x1, y1, x2, y2;
        for(int i = 1; i <= n; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cor.pb({x1 + 1, y1 + 1, y2 + 1, 1});
            cor.pb({x2 + 2, y1 + 1, y2 + 1, -1});
            ycor.pb(y1 + 1), ycor.pb(y2 + 2);
        }
        cout << "case " << i << ": " << query() << "\n";
    }
}
