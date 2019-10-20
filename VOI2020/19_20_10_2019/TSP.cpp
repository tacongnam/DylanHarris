#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
using namespace std;

int n, m, res = INT_MAX, u, v, w;
vector <pii> adj[30];
bool to[30];


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("TSP.inp", "r", stdin);
    freopen("TSP.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    to[1] = true;
    for(int i = 0; i < (1 << 20); i++){

    }
    dq(1, 0, 1, 1);
    cout << res;
}

/*
4 6
1 2 10
2 3 20
1 3 10
4 2 10
3 4 15
4 1 12
*/
