///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define reset(m) memset(m,0,sizeof(m))
#define Task "qos"
#define MOD 1000000007
#define maxn 1005
#define endl "\n"
int n,m,t,delta,cmin=MOD,d[maxn];
long long dp[1003][100200],k;
vector<pii> ke[maxn];
vector<int> ans;
void djk()
{
    for(int i=1; i<=n; ++i)
        d[i]=MOD;
    d[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,1));
    while(pq.size())
    {
        int u=pq.top().S;
        if(u==t) break;
        int du=pq.top().F;
        pq.pop();
        if(du!=d[u])
            continue;
        for(int i=0; i<ke[u].size(); ++i)
        {
            int v=ke[u][i].F;
            int uv=ke[u][i].S;
            if(d[v] > du+uv)
            {
                d[v]=du+uv;
                pq.push(mp(d[v],v));
            }
        }
    }
    if(d[t]==MOD)
    {
        cout<<-1;
        exit(0);
    }
}
long long dfs(int u,int sum)
{
    if(u==t)
    {
        dp[u][sum]=1;
        return 1;
    }
    if(dp[u][sum] > -1)
        return dp[u][sum];
    long long res=0;
    for(int i=0; i<ke[u].size(); ++i)
    {
        int v=ke[u][i].F;
        int uv=ke[u][i].S;
        if(sum + uv <=delta) res+=dfs(v,sum+uv);
    }
    return dp[u][sum]=res;
}
void cal()
{
    int u=1,sum=0;
    while(1)
    {
        ans.pb(u);
        if(u==t)
            break;
        for(int i=0; i<ke[u].size(); ++i)
        {
            int v=ke[u][i].F;
            int uv=ke[u][i].S;
            if(uv+sum > delta) continue;
            if(k > dp[v][sum+uv])
            {
                k-=dp[v][sum+uv];
            }
            else
            {
                u=v;
                sum+=uv;
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); ++i)
        cout<<ans[i]<<" ";
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin );
    freopen(Task".out", "w", stdout );
    cin >> n >> m >> t >> k;
    for(int i=1; i<=m; ++i)
    {
        int u,v,c;
        cin >> u >> v >> c;
        ke[u].pb(mp(v,c));
        cmin=min(cmin,c);
    }
    for(int i=1; i<=n; ++i)
        sort(ke[i].begin(),ke[i].end());
    djk();
    memset(dp,-1,sizeof(dp));
    delta=cmin+d[t];
    dfs(1,0);
    if(k>dp[1][0])
    {
        cout<<-1;
        exit(0);
    }
    cal();
}
