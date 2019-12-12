//ChaeYoungahh
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "ASSIGN"
#define maxn 100005
#define MOD 1000000000
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
using namespace std;
int n,m,Used[maxn],Match[maxn],res,cur;
vector <int> a[maxn];
int FindP(int u)
{
    if(Used[u]== cur) return 0;
    Used[u]=cur;
    for(int i=0; i<a[u].size(); ++i)
    {
        int v=a[u][i];
        if(Match[v]==0 || FindP(Match[v]))
        {
            Match[v]=u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    int u,v;
    while(cin >> u >> v)
    {
        a[u].pb(v);
    }
    for(cur=1; cur<=m; ++cur)
        res+=FindP(cur);
    cout<<res<<endl;
    for(int i=1; i<=n; ++i) cout<<Match[i]<<" ";
}
