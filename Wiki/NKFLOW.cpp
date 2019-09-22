#include <bits/stdc++.h>
#define maxn 200005
#define GTMAX 1000000000000000009
using namespace std;

struct Edge{ //Xet adj[u]
    long long v; //Canh noi tu u -> v
    long long flow; //So capa da dung
    long long c; //Capacity
    long long rev; //Luu tru lai canh dao nguoc trong adj[v]
};

vector <Edge> adj[maxn];
long long level[maxn], start[maxn], s, t, n, m, out[maxn], in[maxn];

void add_edge(long long u, long long v, long long w){
    Edge a = {v, 0, w, adj[v].size()};
    Edge b = {u, 0, 0, adj[u].size()};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

bool bfs(){  //Tra ve true neu con duong, false neu khong con duong
    memset(level, -1, sizeof(level));
    deque <long long> dq;
    level[s] = 0;
    dq.push_back(s);
    while(dq.size() != 0 && level[t] == -1)
    {
        long long u = dq.front();
        dq.pop_front();
        for(long long i = 0; i < adj[u].size(); i++){
            Edge e = adj[u][i];
            if(level[e.v] == -1 && e.flow < e.c){
                level[e.v] = level[u] + 1;
                dq.push_back(e.v);
            }
        }
    }
    return (level[t] != -1);
}

long long dfs(long long u, long long flow){
    if(u == t)
        return flow;
    for(; start[u] < adj[u].size(); start[u]++){
        Edge e = adj[u][start[u]];
        if(level[e.v] == level[u] + 1 && e.flow < e.c){ //Neu co duong di va suc chua van con
            long long curr_flow = min(flow, e.c - e.flow);
            long long temp_flow = dfs(e.v, curr_flow);
            if(temp_flow > 0){ //Neu ton tai duong di
                adj[u][start[u]].flow += temp_flow; //Tang so luong da dung
                adj[e.v][e.rev].flow -= temp_flow; //Giam so luong con lai
                return temp_flow;
            }
        }
    }
    return 0;
}

long long dinic(){
    if(s == t)
        return 0;
    long long total = 0;
    while(bfs() == true){
        memset(start, 0, sizeof(start));
        long long flow = dfs(s, GTMAX);
        while(flow != 0){
            total += flow;
            flow = dfs(s, GTMAX);
        }
    }
    return total;
}

main(){
	scanf("%lld%lld%lld%lld",&n, &m, &s, &t);
    for(long long i = 1; i <= m; i++){
        long long u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        add_edge(u, v, w);
        out[u]++, in[v]++;
    }
    printf("%lld", dinic());
}
