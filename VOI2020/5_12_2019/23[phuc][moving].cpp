///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define reset(m) memset(m,0,sizeof(m))
#define Task "moving"
#define MOD 1000000007
#define maxn 35
#define endl "\n"
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],m,n,dem;
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int T;
vector<pii> vt,pos;
struct edge
{
    int u, v, c, f;
    edge(int _u = 0, int _v=0, int _c=0, int _f=0): u(_u), v(_v), c(_c), f(_f) {};
};
int s, t, current[2000], cnt = 0, d[2000];
long long maxflow = 0;
edge e[100005];
vector <int> ke[2000];
int cal(int i,int j)
{
    return i*m - m + j;
}
void read()
{
    for(int i=0; i<=t; ++i)
         ke[i].clear();
    cnt=0;
    for (int i = 1; i <= n; i++)
        for(int j=1; j<=m; ++j)
        {
            int u=cal(i,j);
            int v=cal(i,j)+m*n;
            if(a[i][j])
            {
                ke[0].pb(cnt);
                e[cnt++] = edge(0,u, 1,0);
                ke[u].pb(cnt);
                e[cnt++] = edge(u,0,0,0);
               c[i][j]++;
            }
            if(b[i][j])
            {
                ke[v].pb(cnt);
                e[cnt++] = edge(v,t,1,0);
                ke[t].pb(cnt);
                e[cnt++] = edge(t,v,0,0);
            }
            ke[u].pb(cnt);
            e[cnt++] = edge(u, v, c[i][j], 0);
            ke[v].pb(cnt);
            e[cnt++] = edge(v, u, 0, 0);
            for(int k=0; k<4; ++k)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x >=1 && x<= n && y<=m && y>=1)
                {
                    int id=cal(x,y);
                    ke[v].pb(cnt);
                    e[cnt++] = edge(v,id,MOD,0);
                    ke[id].pb(cnt);
                    e[cnt++] = edge(id,v,0,0);
                }
            }
        }
}
bool bfs()
{
    memset(d, -1, sizeof(d));
    queue <int> qu;
    qu.push(s);
    d[s] = 0;
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (int i = 0; i < ke[u].size(); i++)
        {
            int id = ke[u][i];
            int v = (e[id].f < e[id].c) ? e[id].v : s;
            if (d[v]!= -1)
                continue;
            qu.push(v);
            d[v] = d[u] + 1;

        }
    }
    return d[t] > 0;
}
int dfs(int u, int val)
{
    if (u == t)
        return val;
    for (int &i = current[u]; i < ke[u].size(); i++)
    {
        int id = ke[u][i];
        int v = e[id].v;
        if (d[v] == d[u] + 1 && e[id].f < e[id].c)
        {
            int val1=min(val,e[id].c - e[id].f);
            int foo = dfs(v, val1);
            if (foo != 0)
            {
                e[id].f += foo;
                e[id ^ 1].f -= foo;
                return foo;
            }
        }
    }
    return 0;
}
//void dfs1(int x,int y)
//{
//    d[x][y]=1;
//    for(int i=0; i<4; ++i)
//    {
//        int u=x+dx[i];
//        int v=y+dy[i];
//        if(u > 0 && u <= n && v>=1 && v<=m && !d[u][v] && c[u][v])
//            dfs1(u,v);
//    }
//}
//void sub2()
//{
//    dfs1(vt[0].F,vt[0].S);
//    if(d[pos[0].F][pos[0].S])
//        cout<<1;
//    else
//        cout<<0;
//    cout<<endl;
//}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin );
    freopen(Task".out", "w", stdout );
    cin >> T;
    while(T--)
    {
        reset(d);
        vt.clear();
        dem=0;
        int minn=MOD;
        pos.clear();
        cin >> n >> m;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                cin >> a[i][j];
                dem+=a[i][j];
                if(a[i][j]==1)
                    vt.pb(mp(i,j));
            }
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                cin >> b[i][j];
                if(b[i][j])
                    pos.pb(mp(i,j));
            }
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                cin >> c[i][j];
                minn=min(minn,c[i][j]);
            }
        if(minn >= 900)
            cout<<dem<<endl;
//        else if(dem==1)
//            sub2();
        else
        {
            s=0;
            t=2*m*n + 1;
            read();
            long long res = 0;
            while (bfs())
            {
                for (int i = 0; i <= t ; ++i)
                    current[i] = 0;
                while (1)
                {
                    int foo = dfs(s, 2000000000);
                    if (!foo)
                        break;
                    res += foo;
                }
            }
            cout << res << endl;
        }
    }
}
