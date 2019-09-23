#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
#define For(a, b, c) for(a = b; a <= c;  a++)
#define Ford(a, b, c) for(a = b; a >= c; a--)
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

vector <Edge> adj[maxn];
int n, m, s, t, level[maxn], start[maxn];
pair<int, int> ans[maxn];

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
    while(dq.size()){
        int u = dq.front();
        dq.pop_front();
        for(int i = 0; i < adj[u].size(); i++){
            Edge e = adj[u][i];
            if(level[e.v] == -1 && e.flow < e.c){
                dq.push_back(e.v);
                level[e.v] = level[u] + 1;
            }
        }
    }
    return (level[t] != -1);
}

int dfs(int u, int flow, int pa){
    if(u == t)
        return flow;
    for(; start[u] < adj[u].size(); start[u]++){
        Edge e = adj[u][start[u]];
        if(level[e.v] == level[u] + 1 && e.flow < e.c){
            int curr_flow = min(flow, e.c - e.flow);
            int temp_flow = dfs(e.v, curr_flow, u);
            if(temp_flow > 0){
                adj[u][start[u]].flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                adj[u][start[u]].change();
                adj[e.v][e.rev].change();
                if(adj[u][start[u]].match == true){
                    if(u > 0 && u <= n)
                        ans[u].first = e.v;
                    else if(n + m + 1 <= u && u <= 2 * n + m)
                        ans[u].second = pa;
                }
                else{
                    if(u > 0 && u <= n)
                        ans[u].first = n;
                    else if(n + m + 1 <= u && u <= 2 * n + m)
                        ans[u].second = n;
                }
                return temp_flow;
            }
        }
    }
    return 0;
}

int dinic(){
    if(s == t)
        return -1;
    int total = 0;
    while(bfs() == true){
        memset(start, 0, sizeof(start));
        int flow = dfs(s, INT_MAX, -1);
        while(flow > 0){
            total += flow;
            flow = dfs(s, INT_MAX, -1);
        }
    }
    return total;
}

void input(string s, int type, int val){
    //start: 0
    //Chuyen SP: 1 -> n
    //Problem: n + 1 -> n + m
    //Chuyen TH: n + m + 1 -> 2 * n + m
    //end: 2 * n + m + 1
    int num = 0;
    s = s + ' ';
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            num = num * 10 + (s[i] - 48);
        else if(type == 1) //chuyen SP to Problem
            add_edge(val, num + n, 1), num = 0;
        else if(type == 2) //Problem to Chuyen TH
            add_edge(num + n, val, 1), num = 0;
    }
    return;
}

int output(){
    /* Answer *//*
    for(int i = s; i <= t; i++){
        cout << "Node " << i << ": ";
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j].v << " ";
        cout << endl;
    }
    */
    int di = dinic(), answ[] = {4, 6, 1, 4, 5, 6, 5, 4, 1}, cnt = 0;
    int fail = 0;
    cout << "Answer: " << di << endl;
    if(di != answ[cnt])
        fail = 1;
    for(int i = 1; i <= n; i++){
        cout << "SP " << i << " " << ans[i].first - n << endl;
        if(ans[i].first - n != answ[++cnt])
            fail = i + 1;
    }
    for(int i = n + m + 1; i <= 2 * n + m; i++){
        cout << "TH " << i - n - m << " " << ans[i].second - n << endl;
        if(ans[i].second - n != answ[++cnt])
            fail = i - m + 1;
    }
    return fail;
}

string st;
int main()
{
    fi("FLOW1.inp");
    //fo(".inp");
    cin >> n >> m;
    cin.ignore();
    s = 0, t = 2 * n + m + 1;
    for(int i = 1; i <= n; i++){
		//fflush(stdin);
        getline(cin, st);
        input(st, 1, i);
        add_edge(s, i, 1);
    }
    for(int i = n + m + 1; i <= n * 2 + m; i++){
		//fflush(stdin);
        getline(cin, st);
        input(st, 2, i);
        add_edge(i, t, 1);
    }
    int f = output();
    if(f == 0)
        cout << "\n Ok, correct answer \n";
    else
        cout << "\n Wrong answer at line " << f << endl;
}
