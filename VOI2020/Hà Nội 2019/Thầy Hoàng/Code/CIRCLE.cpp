///....DH....///
#include <bits/stdc++.h>
#define task "CIRCLE"
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

template <typename T> inline void out(T x) { ///use for long long, int
    if(x > 9)
        out(x / 10);
    putchar(x % 10 + 48);
}

template <typename T> inline void outsp(T x) {
    out(x);
    putchar(' ');
}

template <typename T> inline void outln(T x) {
    out(x);
    putchar('\n');
}

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

const int mod = 1e9 + 7;
const int maxn = 1000005;
int n, a[maxn], d[maxn], beg[maxn], en[maxn], cnt;
vector <int> adj[maxn];
queue <int> q1, q2;

int dfs(int u) {
    d[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(d[v] == 0)
            return dfs(v);
    }
    return u;
}

int ne[maxn];
pii res[maxn];
queue <int> qu1, qu2;

main() {
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    inp(n);
    for(int i = 1; i <= n; i++) {
        inp(ne[i]);
        adj[i].push_back(ne[i]);
        d[ne[i]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(d[i] == 0)
            qu1.push(i);
        else
            qu2.push(i);
        d[i] = 0;
    }
    int start = 0;
    if(qu1.size() > 0)
        start = qu1.front();
    else
        start = 1;
    while(qu1.size() > 0) {
        int u = qu1.front();
        qu1.pop();
        int v = dfs(u);
        while(qu2.size() > 0 && d[qu2.front()] == 1)
            qu2.pop();
        if(qu1.size() == 0 && qu2.size() == 0) {
            res[++cnt] = mp(v, start);
            break;
        }
        if(qu1.size() == 0) {
            res[++cnt] = mp(v, qu2.front());
            break;
        }
        res[++cnt] = mp(v, qu1.front());
    }
    while(qu2.size() > 0) {
        int u = qu2.front();
        qu2.pop();
        int v = dfs(u);
        while(qu2.size() > 0 && d[qu2.front()] == 1)
            qu2.pop();
        if(qu2.size() == 0) {
            if(ne[v] == start)
                break;
            else {
                res[++cnt] = mp(v, start);
                break;
            }
        }
        res[++cnt] = mp(v, qu2.front());
    }
    outln(cnt);
    for(int i = 1; i <= cnt; i++)
        outsp(res[i].first), outln(res[i].second);
}
