/// ---------- /// dylanrhodes /// ---------- ///
#include <bits/stdc++.h>
#define f first
#define s second
#define reset(x,a) memset(x,a,sizeof(x))
#define task "QOS"

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1005;
int n,m,t,k,cmin = INT_MAX,tmin;
int dist[N];
vector <pair <int,int> > adj[N];

long long dij () {
    for (int i = 2; i <= n; i++)
        dist[i] = INT_MAX;
    dist[1] = 0;
    priority_queue <pair<int,int> > hp;
    hp.push({dist[1],1});
    while (hp.size()) {
        int u = hp.top().s;
        int du = -hp.top().f;
        hp.pop();
        if (du != dist[u])
            continue;
        for (long long i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].f;
            int w = adj[u][i].s;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                hp.push({-dist[v],v});
            }
        }
    }
    if (dist[t] == 1e18)
        return -1;
    else
        return dist[t];
}

string T;
vector <string> a;

void duyet (int u,int d) {
    if (u == t) {
        a.push_back(T);
        return;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].f;
        int w = adj[u][i].s;
        if (d + w <= tmin) {
            string add = "0";
            add[0] = char(v + '0');
            T.insert(T.size(),add);
            duyet(v,d+w);
            T.erase(T.size()-1,1);
        }
    }
}

long long dp[N][100005];

long long calc (int u,int d) {
    if (u == t)
        return 1;
    if (dp[u][d] > -1)
        return dp[u][d];
    long long res = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].f;
        int w = adj[u][i].s;
        if (d + w <= tmin) {
            res += calc(v,d+w);
        }
    }
    return dp[u][d] = res;
}

vector <int> luu;

void truy (int u,int d) {
    if (k <= calc(u,d)) {
        luu.push_back(u);
        if (u == t)
            k = -1;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].f;
            int w = adj[u][i].s;
            if (d + w <= tmin) {
                truy(v,d+w);
                if (k == -1)
                    return;
            }
        }
    } else {
        k -= calc(u,d);
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);

    cin >> n >> m >> t >> k;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        cmin = min(cmin,w);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(),adj[i].end());
    if (dij() == -1)
        cout << -1;
    else {
        tmin = dist[t] + cmin;
        if (n <= 10) {
            T = "1";
            duyet(1,0);
            sort(a.begin(),a.end());
            if (a.size() >= k) {
                cout << a[k-1].size() << "\n";
                for (int i = 0; i < a[k-1].size(); i++)
                    cout << a[k-1][i] << " ";
            } else
                cout << -1;
        } else {
            memset(dp,-1,sizeof(dp));
            if (calc(1,0) < k)
                cout << -1;
            else {
                memset(dp,-1,sizeof(dp));
                calc(1,0);
                truy(1,0);
                cout << luu.size() << "\n";
                for (int i = 0; i < luu.size(); i++)
                    cout << luu[i] << " ";
            }
        }

    }
    return 0;
}
