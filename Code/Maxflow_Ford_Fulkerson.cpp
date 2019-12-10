/**

//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "maxflow"
#define maxn 1002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int c[maxn][maxn], f[maxn][maxn], n, m, s, t;
int tr[maxn];
int maxflow = 0;
int tt = 0;

void read()
{
    cin >> n >> m >> s >> t;
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        //cout << u << v << endl;
        cin >> c[u][v];
    }
}

void DFS(int u)
{
    for (int i = 1; i <= n; i++)
        if (tr[i] == 0 && c[u][i] > f[u][i]){
            tr[i] = u;
            DFS(i);
        }
}

bool Find_path()
{
    memset(tr, 0, sizeof(tr));
    tr[s] = -1;// khac 0
    DFS(s);
    return (tr[t]);
}

void IncFlow()
{
    tt++;
    int delta = MOD;
    int u = t;
    while (u != s){
        int v = tr[u];
        MIN(delta, c[v][u] - f[v][u]);
        u = v;
    }
    u = t;
    while (u != s)
    {
        int v = tr[u];
        f[u][v] -= delta;
        f[v][u] += delta;
        u = v;
    }
    maxflow += delta;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    read();
    while (Find_path())
        IncFlow();
    cout << maxflow;
    cerr << tt;
    return 0;
}


**/
