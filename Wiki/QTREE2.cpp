#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int d[maxn], pa[20][maxn], len[20][maxn], n, t;
vector< pair<int,int> > g[maxn];

void dfs(int u, int p){
    d[u] = d[p] + 1;
    pa[0][u] = p;
    for(int i = 1; i <= 16; i++){
        pa[i][u] = pa[i-1][pa[i-1][u]];
        len[i][u] = len[i-1][u] + len[i-1][pa[i-1][u]];
    }
    for(int i = 0; i < g[u].size(); i++){
        pair<int,int> v = g[u][i];
        if(v.first != p){
            len[0][v.first] = v.second;
            dfs(v.first, u);
        }
    }
}
pair<int, int> dist(int u, int v){
    if(d[u] < d[v])
        swap(u, v);
    int dist = 0;
    for(int i = 16; i >= 0; i--)
        if((d[u] - d[v]) >= (1 << i))
            dist += len[i][u], u = pa[i][u];
    if(u == v)
        return make_pair(u, dist);
    for(int i = 16; i >= 0; i--)
        if(pa[i][u] != pa[i][v]){
            dist += len[i][u] + len[i][v];
            u = pa[i][u];
            v = pa[i][v];
        }
    dist += len[0][u] + len[0][v];
    return make_pair(pa[0][u], dist);
}

int kth(int u, int v, int lca, int k){
    //Xem kth ở nhánh nào:
    if(d[u] - d[lca] + 1 >= k){ //Thuộc nhánh u -> lca
        int jump = 1, node = u;
        for(int i = 16;i >= 0; i--)
            if(jump + (1 << i) <= k)
                jump += (1 << i), node = pa[i][node];
        return node;
    }
    else{ //Thuộc nhánh lca -> v
        //Tính xem jump đến đâu:
        int pos = (d[v] - d[lca] + 1) - (k - (d[u] - d[lca]));
        int node = v;
        for(int i = 16; i >= 0; i--)
            if(pos >= (1 << i))
                pos -= (1 << i), node = pa[i][node];
        return node;
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            g[i].clear();
        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        d[1] = 0;
        dfs(1, 1);
        string s;
        while(cin >> s){
            if(s[0] == 'D' && s[1] == 'O')
                    break;
            if(s[0] == 'D' && s[1] == 'I'){
                int u, v;
                cin >> u >> v;
                cout << dist(u, v).second << endl;
            }
            if(s[0] == 'K'){
                int u, v, k;
                cin >> u >> v >> k;
                pair<int,int> lc = dist(u, v);
                cout << kth(u, v, lc.first, k) << endl;
            }
        }
    }
}
