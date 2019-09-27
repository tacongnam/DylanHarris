#include <bits/stdc++.h>
#define maxn 400005
#define ll long long
#define mod 1000000007
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
using namespace std;

struct Edge{
    int v, flow, c, rev;
    bool match;
    void change(){
        match = 1 - match;
    }
};

int n, a[maxn], res, m, s, t, start[maxn], level[maxn], nx, ny, u, v;
int ans[maxn], r[maxn];
vector <Edge> adj[maxn];

void add_edge(int u, int v, int w){
    Edge a = {v, 0, w, adj[v].size()};
    Edge b = {u, 0, 0, adj[u].size()};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

bool bfs(){
    memset(level, -1, sizeof(level));
    deque <int> dq;
    dq.push_back(s);
    level[s] = 0;
    while(dq.size() != 0){
        int u = dq.front();
        dq.pop_front();
        for(int i = 0; i < adj[u].size(); i++){
            Edge e = adj[u][i];
            if(level[e.v] == -1 && e.flow < e.c){
                level[e.v] = level[u] + 1;
                dq.push_back(e.v);
            }
        }
    }
    return (level[t] != -1);
}

int dfs(int u, int flow){
    if(u == t){
        return flow;
    }
    for(; start[u] < adj[u].size(); start[u]++){
        Edge e = adj[u][start[u]];
        if(level[e.v] == level[u] + 1 && e.flow < e.c){
            int curr_flow = min(flow, e.c - e.flow);
            int temp_flow = dfs(e.v, curr_flow);
            if(temp_flow > 0){
                adj[u][start[u]].flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                /// Matching
                adj[u][start[u]].change();
                adj[e.v][e.rev].change();
                if(adj[e.v][e.rev].match == true)
                    ans[u] = e.v;
                else
                    ans[u] = 0;
                /// End of matching
                return temp_flow;
            }
        }
    }
    return 0;
}

int dinic(){
    int total = 0;
    while(bfs() == true){
        memset(start, 0, sizeof(start));
        int flow = dfs(s, INT_MAX);
        while(flow > 0){
            total += flow;
            flow = dfs(s, INT_MAX);
        }
    }
    for(int i = 1; i <= nx; i++)
        if(r[max(ans[i] - nx, 0)] == 0)
            r[max(ans[i] - nx, 0)] = i;
    return total;
}

bool check(int u, int v){
    for(int i = 0; i < adj[u].size(); i++)
        if(adj[u][i].v == v + nx)
            return false;
    return true;
}

int main()
{
    fi("MASSIGN.inp");
    //fo("MASSIGN.out");
    cin >> nx >> ny;
    int num = ny;
    for(int i = 1; i <= nx; i++)
        add_edge(0, i, 1);
    while( cin >> u >> v ){
        if(check(u, v) == true)
            add_edge(u, v + nx, 1);
    }
    s = 0;
    t = nx + ny + 1;
    for(int i = 1; i <= ny; i++)
        add_edge(i + nx, t, 1);
    while(num != 0){
        adj[s].clear();
        for(int i = 1; i <= nx; i++)
            add_edge(s, i, 1);
        for(int i = 1; i <= nx; i++)
            adj[i][0].flow = 0;
        num -= dinic();
        res++;
    }
    cout << res << endl;
    for(int i = 1; i <= ny; i++)
        cout << r[i] << " ";
    //for(int i = 1; i <= cnt; i++){
    //    cout << ans[i].first << " " << ans[i].second << endl;
    //}
}