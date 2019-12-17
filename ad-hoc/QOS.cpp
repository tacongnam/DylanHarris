///....DH....///
#include <bits/stdc++.h>
#define task "QOS"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
#define pli pair<long long, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
#define For(i, s, n, m) for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m) for(int i = s; i >= n; i -= m)
using namespace std;

template <typename R, typename D> inline void Min(R &a, D b)
{
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b)
{
    if(a<b)
        a=b;
}

const int mod = 1e9 + 7;
const int maxn = 1005;

vector <int> ans;
int n, m, t, k, len, d[maxn];
long long dp[1003][100003];
vector < pair <int, int> > adj[maxn];
bool vi[maxn];

long long digit (int u, long long sum) {
    if(sum > len)
        return 0;
    if(u == t) {
        dp[u][sum] = 1;
        return 1;
    }
    if(dp[u][sum] > -1)
        return dp[u][sum];
    vi[u] = true;
    long long res = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        pair <int, int> v = adj[u][i];
        if(vi[v.ft] == false && sum + v.sd <= len)
            res += digit(v.ft, sum + v.sd);
    }
    vi[u] = false;
    dp[u][sum] = res;
    return res;
}

void truyvet(int u, int sum, int pos) {
    ans.pb(u);
    if(u == t) {
        printf("%d\n", int(ans.size()));
        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        exit(0);
    }
    vi[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        pair <int, int> v = adj[u][i];
        if(vi[v.ft] == false && sum + v.sd <= len) {
            if(pos + dp[v.ft][sum + v.sd] >= k)
                truyvet(v.ft, sum + v.sd, pos);
            else
                pos += dp[v.ft][sum + v.sd];
        }
    }
    return ;
}

void dijk(int s)
{
    for(int i = 1; i <= n; i++)
        d[i] = 1e9;
    priority_queue < pii, vector < pii >, greater < pii > > pq;
    pq.push(mp(0, s));
    d[s] = 0;
    while(pq.size() > 0)
    {
        pli u = pq.top();
        pq.pop();
        if(vi[u.sd] == true)
            continue;
        vi[u.sd] = true;
        for(int i = 0; i < adj[u.sd].size(); i++)
        {
            pii v = adj[u.sd][i];
            if(d[v.ft] > d[u.sd] + v.sd)
            {
                d[v.ft] = d[u.sd] + v.sd;
                pq.push(mp(d[v.ft], v.ft));
            }
        }
    }
    return ;
}

int u, v, c;

main()
{
    fi("QOS.inp");
    fo("QOS.out");
    scanf("%d%d%d%d", &n, &m, &t, &k);
    len = 1e9;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(mp(v, c));
        Min(len, c);
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    dijk(1);
    len += d[t];
    memset(dp, -1, sizeof(dp));
    memset(vi, 0, sizeof(vi));
    long long ss = digit(1, 0);
    if(ss < k)
        cout << -1;
    else
        truyvet(1, 0, 0);
}
