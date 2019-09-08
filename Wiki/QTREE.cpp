#include <bits/stdc++.h>
using namespace std;

long long sz[10005], d[10005], pa[20][10005], val[10005], pos[10005], chain[10005], head[10005], ver[10005], r[10005];
long long nchain, cnt, n, st[40005], t;
vector < pair<long long,long long> > g[10005];
vector < pair<long long,long long> > edge;

void dfs(long long u, long long p){
    sz[u] = 1;
    d[u] = d[p] + 1;
    pa[0][u] = p;
    for(long long i = 1; i <= 16; i++)
        pa[i][u] = pa[i-1][pa[i-1][u]];
    for(long long i = 0; i < g[u].size(); i++){
        pair<long long, long long> v = g[u][i];
        if(d[v.first] == 0){
            dfs(v.first, u);
            sz[u] += sz[v.first];
            val[v.first] = v.second;
        }
    }
}

void hld (long long u){
    if(head[nchain] == 0)
        head[nchain] = u;
    pos[u] = ++cnt;
    ver[cnt] = u;
    chain[u] = nchain;
    long long sc = 0;
    for(long long i = 0; i < g[u].size(); i++){
        pair<long long,long long> v = g[u][i];
        if(pos[v.first] == 0 && sz[v.first] > sz[sc])
            sc = v.first;
    }
    if(sc != 0)
        hld(sc);
    for(long long i = 0; i < g[u].size(); i++){
        pair<long long,long long> v = g[u][i];
        if(pos[v.first] == 0)
            nchain++, hld(v.first);
    }
}

void make_st(long long id, long long l, long long r){
    if(l > r)
        return;
    if(l == r){
        st[id] = val[ver[l]];
        return;
    }
    make_st(id*2, l, (l+r)/2);
    make_st(id*2+1, (l+r)/2+1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}

void update(long long id, long long l, long long r, long long po, long long va){
    if(po < l || po > r)
        return;
    if(l == r){
        st[id] = va;
        val[ver[l]] = va;
        return;
    }
    update(id*2, l, (l+r)/2, po, va);
    update(id*2+1, (l+r)/2+1, r, po, va);
    st[id] = max(st[id*2], st[id*2+1]);
}

long long get(long long id, long long l, long long r, long long u, long long v){
    if(r < u || v < l)
        return -1e18;
    if(u <= l && r <= v)
        return st[id];
    long long a = get(id*2, l, (l+r)/2, u, v);
    long long b = get(id*2+1, (l+r)/2+1, r, u, v);
    return max(a, b);
}

long long lca (long long u, long long v){
    if(d[u] < d[v])
        swap(u, v);
    for(long long i = 16; i >= 0; i--)
        if((d[u] - d[v]) >= (1 << i))
            u = pa[i][u];
    if(u == v)
        return u;
    for(long long i = 16; i >= 0; i--)
        if(pa[i][u] != pa[i][v])
            u = pa[i][u], v = pa[i][v];
    return pa[0][u];
}

long long gethld(long long u, long long v){
    long long res = -1e18;
    while(chain[u] != chain[v]){
        res = max(res, get(1, 1, n, pos[head[chain[u]]], pos[u]));
        u = pa[0][head[chain[u]]];
    }
    res = max(res, get(1, 1, n, pos[v] + 1, pos[u]));
    return res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){

        memset(d, 0, sizeof(d));
        memset(head, 0, sizeof(head));
        memset(sz, 0, sizeof(sz));
        memset(pos, 0, sizeof(pos));
        memset(chain, 0, sizeof(chain));
        memset(ver, 0, sizeof(ver));
        memset(r, 0, sizeof(r));
        memset(st, 0, sizeof(st));
        memset(pa, 0, sizeof(pa));
        edge.clear();

        cin >> n;
        for(long long i = 1; i < n; i++){
            long long u, v, w;
            cin >> u >> v >> w;
            edge.push_back(make_pair(u,v));
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        dfs(1,1);
        for(long long i = 0; i < edge.size(); i++){
            if(d[edge[i].first] > d[edge[i].second])
                r[i+1] = edge[i].first;
            else
                r[i+1] = edge[i].second;
        }
        nchain = 1, cnt = 0;
        hld(1);
        make_st(1, 1, n);
        cin.ignore();
        string s;
        while(cin >> s){
            if(s[0] == 'D')
                break;
            if(s[0] == 'C'){
                long long po, va;
                cin >> po >> va;
                update(1, 1, n, pos[r[po]], va);
            }
            if(s[0] == 'Q'){
                long long u, v;
                cin >> u >> v;
                if(u == v){
                    cout << -1000000007 << endl;
                    continue;
                }
                long long lc = lca(u, v);
                cout << max(gethld(u, lc), gethld(v, lc)) << endl;
            }
        }

        for(long long i = 1; i <= n; i++)
            g[i].clear();
    }
}
