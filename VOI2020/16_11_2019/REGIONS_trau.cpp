//                                /----------/// dylanrhodes ///----------///
//#include <bits/stdc++.h>
//#define f first
//#define s second
//#define reset(x,a) memset (x,a,sizeof(x))
//#define task "REGIONS"
//
//using namespace std;
//
//const int MOD = 1e9 + 7;
//const int N = 100005;
//int n,m,k,dem = 0,edge = 0;
//int num[N],low[N];
//pair <int,int> tplt[N];
//vector <int> adj[N];
//stack <int> st;
//
//void dfs (int u){
//    st.push(u);
//    num[u] = ++ num[0];
//    low[u] = n + 1;
//    edge += adj[u].size();
//
//    for (int i = 0; i < adj[u].size(); i++){
//        int v = adj[u][i];
//        if (num[v]) low[u] = min(low[u],num[v]);
//        else {
//            dfs(v);
//            low[u] = min(low[u],low[v]);
//        }
//    }
//
//    if (num[u] <= low[u]){
//        int cnt = 0;
//        while (st.top() != u){cnt++; st.pop();}
//        cnt++;
//        st.pop();
//        tplt[++dem].f = cnt;
//        tplt[dem].s = edge/2;
//        edge = 0;
//    }
//}
//
//int main(){
//    std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
//    freopen (task".inp","r",stdin);
//    freopen (task".ans","w",stdout);
//
//    cin >> n >> m >> k;
//    for (int i = 1; i <= m; i++){
//        int u,v;
//        cin >> u >> v;
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (!num[i]) dfs(i);
//
//    int MIN = max(dem - k,1);
//    int MAX = dem;
//    sort(tplt + 1,tplt + 1 + dem);
//    for (int i = 1; i <= dem; i++)
//        k -= max(0,(tplt[i].f - 1)*tplt[i].f/2 - tplt[i].s);
//    for (int i = dem; i >= 2; i--){
//        if (k <= 0) break;
//        k -= tplt[i].f*tplt[i-1].f;
//        tplt[i-1].f = tplt[i].f+tplt[i-1].f;
//        MAX --;
//    }
//
//    cout << MIN << " " << max(1,MAX);
//    return 0;
//}
