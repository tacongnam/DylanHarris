#include <bits/stdc++.h>
#define maxn 200005
#define ft first
#define sd second
#define pii pair<int, int>
using namespace std;
 
const int wblock = 410;
const int nblock = 260;
const int total = nblock * wblock;
 
int d[maxn], pa[20][maxn], a[maxn], beginpos[maxn], endpos[maxn], wa[maxn], block[maxn], cnt[maxn], ans[maxn], counter;
int n, qu, s;
vector <pii> g[maxn];
bool vi[maxn];
 
struct QUERY {
    int l, r, in, l1, lc;
    bool operator < (const QUERY &P) {
        return ((l1 < P.l1) || (l1 == P.l1 && r < P.r));
    }
} q[maxn];
 
void dfs(int u, int p, int w) {
    d[u] = d[p] + 1;
    pa[0][u] = p;
    a[++counter] = u;
    wa[u] = w;
    beginpos[u] = counter;
    for(int i = 1; i <= 16; i++)
        pa[i][u] = pa[i-1][pa[i-1][u]];
    for(int i = 0; i < g[u].size(); i++) {
        pii v = g[u][i];
        if(v.ft != p)
            dfs(v.ft, u, v.sd);
    }
    a[++counter] = u;
    wa[u] = w;
    endpos[u] = counter;
}
int lca(int u, int v) {
    if(d[u] < d[v])
        swap(u, v);
    for(int i = 16; i >= 0; i--)
        if((d[u] - d[v]) >= (1 << i))
            u = pa[i][u];
    if(u == v)
        return u;
    for(int i = 16; i >= 0; i--)
        if(pa[i][u] != pa[i][v])
            u = pa[i][u], v = pa[i][v];
    return pa[0][u];
}
 
void remov(int pos) {
    int w = wa[pos] / wblock;
    if(cnt[wa[pos]] == 1)
        block[w]--;
    cnt[wa[pos]]--;
}
 
void add(int pos) {
    int w = wa[pos] / wblock;
    if(cnt[wa[pos]] == 0)
        block[w]++;
    cnt[wa[pos]]++;
}
 
void modify (int pos) {
    if(wa[pos] >= 100005)
        return;
    if(vi[pos] == true)
        remov(pos), vi[pos] = false;
    else
        add(pos), vi[pos] = true;
}
 
int query() {
    for(int i = 0; i < nblock; i++) {
        if(block[i] <= wblock) {
            for(int j = wblock * i; j < wblock * (i + 1); j++) {
                if(cnt[j] == 0)
                    return j;
            }
        }
    }
}
 
main() {
    scanf("%d%d", &n, &qu);
    s = sqrt(2 * n);
    for(int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dfs(1, 0, 200000);
    for(int i = 1; i <= qu; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        int lc = lca(u, v);
        if(lc == u)
            q[i] = {endpos[v], endpos[u], i, endpos[v] / s, lc};
        else if(lc == v)
            q[i] = {endpos[u], endpos[v], i, endpos[u] / s, lc};
        else if(endpos[v] < beginpos[u])
            q[i] = {endpos[v], beginpos[u], i, endpos[v] / s, lc};
        else if(endpos[u] < beginpos[v])
            q[i] = {endpos[u], beginpos[v], i, endpos[u] / s, lc};
    }
    sort(q + 1, q + qu + 1);
    int curl = 1, curr = 1;
    modify(a[1]);
    for(int i = 1; i <= qu; i++){
        while(curl < q[i].l)
            modify(a[curl++]);
        while(curl > q[i].l)
            modify(a[--curl]);
        while(curr < q[i].r)
            modify(a[++curr]);
        while(curr > q[i].r)
            modify(a[curr--]);
        if(a[q[i].l] != a[q[i].r]){
            if(q[i].lc == a[q[i].l] || q[i].lc == a[q[i].r])
                modify(q[i].lc);
            ans[q[i].in] = query();
            if(q[i].lc == a[q[i].l] || q[i].lc == a[q[i].r])
                modify(q[i].lc);
        }
        else
            ans[q[i].in] = 0;
    }
    for(int i = 1; i <= qu; i++)
        printf("%d\n", ans[i]);
}
