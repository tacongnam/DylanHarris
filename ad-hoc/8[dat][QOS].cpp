///-----------------Quyet Tam Vong 2-----------------
#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define f first
#define s second
//#define int long long
using namespace std;

const int N = 5005;
const int MOD = 1000000007;
int n, m, k, T;
vector < pair < int, int > > ke[N], trc[N][305];
int Cmin = 500, d[N];
bool luu[N][305];
long long dp[N][305], F[N][305];
int b[50005], dem = 0;
void dijkstra1()
{
    priority_queue < pair < int, int > > pq;
    FOR(i, 1, n) d[i] = MOD;
    d[1] = 0;
    pq.push(mp(0, 1));
    while(pq.size())
    {
        int du = -pq.top().f;
        int u = pq.top().s;
        pq.pop();
        if(d[u] != du) continue;
        for(int i = 0; i < ke[u].size(); i ++)
        {
            int v = ke[u][i].f;
            int uv = ke[u][i].s;
            if(d[v] > d[u] + uv)
            {
                d[v] = d[u] + uv;
                pq.push(mp(-d[v], v));
            }
        }
    }
}
void dijkstra2()
{
    FOR(i, 1, n)
    {
        FOR(j, 0, Cmin)
        {
            dp[i][j] = -1;
        }
    }
    dp[1][0] = 1;
    priority_queue < pair < int, pair < int, int > > > pq;
    pq.push(mp(0, mp(1, 0)));
    while(pq.size())
    {
        int u = pq.top().s.f;
        int du = -pq.top().f;
        int kc = pq.top().s.s;
        pq.pop();
        for(int i = 0; i < ke[u].size(); i ++)
        {
            int v = ke[u][i].f;
            int uv = ke[u][i].s;
            int nkc = du + uv - d[v];
            if(nkc > Cmin) continue;
            if(dp[v][nkc] == -1)
            {
                dp[v][nkc] = 1;
                trc[v][nkc].push_back(mp(u, kc));
                pq.push(mp(-(d[v] + nkc), mp(v, nkc)));
            }
            else
            {
                trc[v][nkc].push_back(mp(u, kc));
            }
        }
    }
    priority_queue < pair < int, pair < int, int > > > pq1;
    FOR(i, 0, Cmin)
    {
        if(dp[T][i] != -1)
        {
            F[T][i] = 1;
            luu[T][i] = 1;
            pq1.push(mp(d[T] + i, mp(T, i)));
//            cout << T << " " << i << "\n";
        }
    }
    while(pq1.size())
    {
        int u = pq1.top().s.f;
        int du = pq1.top().f;
        int kc = pq1.top().s.s;
        pq1.pop();
        for(int i = 0; i < trc[u][kc].size(); i ++)
        {
            int v = trc[u][kc][i].f;
            int nkc = trc[u][kc][i].s;
            if(luu[v][nkc] == 0)
            {
                luu[v][nkc] = 1;
                F[v][nkc] += F[u][kc];
                pq1.push(mp(d[v] + nkc, mp(v, nkc)));
            }
            else
            {
                F[v][nkc] += F[u][kc];
            }
        }
    }
}
void DFS(int u, int dd)
{
    b[++ dem] = u;
    priority_queue < pair < int, int > > pq;
    for(int i = 0; i < ke[u].size(); i ++)
    {
        int v = ke[u][i].f;
        int w = ke[u][i].s;
        int kc = dd + w - d[v];
        if(F[v][kc]) pq.push(mp(-v, kc));
    }
    while(pq.size())
    {
        int v = -pq.top().f;
        int kc = pq.top().s;
        pq.pop();
        if(k > F[v][kc]) k -= F[v][kc];
        else
        {
            DFS(v, d[v] + kc);
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("QOS.inp","r",stdin);
    freopen("QOS.out","w",stdout);
    cin >> n >> m >> T >> k;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].push_back(mp(v, w));
//        ke1[v].push_back(mp(u, w));
        Cmin = min(Cmin, w);
    }
    dijkstra1();
//    cout << d[n] << " " << d[6] << " " << d[4] << " " << d[3] << "\n";
    dijkstra2();
    long long sum = 0;
    FOR(i, 0, Cmin) sum += F[1][i];
    if(sum < k) cout << -1;
    else
    {
        DFS(1, 0);
        cout << dem << "\n";
        FOR(i, 1, dem) cout << b[i] << " ";
    }
    return 0;
}
