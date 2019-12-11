https://vn.spoj.com/problems/MATCH1/

///....DH....///
#include <bits/stdc++.h>
#define task ""
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
#define For(i, s, n, m) for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m) for(int i = s; i >= n; i -= m)
using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

const int mod = 1e9 + 7;
const int maxn = 200005;

int n, m, res, x[maxn], d[maxn], y[maxn];
vector <int> g[maxn];

bool Find() {
    queue <int> qu;
    for(int i = 1; i <= m; i++) {
        if(x[i] == 0) {     /// i (X) chưa được ghép
            d[i] = 0;       /// Tạo đường mở bắt đầu từ i (X)
            qu.push(i);     /// Thêm i (X) vào queue
        }
        else                /// Nếu đã duyệt rồi
            d[i] = 1e9;     /// gán d[i] = 1e9 để không duyệt lại
    }

    /// gán d[0] trong trường hợp j (Y) không nối được với i (X)
    /// nào (nối với đỉnh 0)
    d[0] = 1e9;

    /// BFS tạo bậc để xây dựng đường mở
    while(qu.size() > 0) {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < g[u].size(); i++) {
            /// Xét đỉnh kề với u (X) (những đỉnh nối với u (X)
            /// ở tập (Y)
            int v = g[u][i];

            if(d[y[v]] == 1e9) {
                d[y[v]] = d[u] + 1;
                /// Nếu v (Y) đã được ghép thì cho vào hàng đợi
                if(y[v] != 0)
                    qu.push(y[v]);
            }
        }
    }

    /// Nếu tồn tại đỉnh v (Y) chưa được ghép
    return (d[0] != 1e9);
}

bool dfs(int u) {
    if(u == 0)      /// Kết thúc đường mở / đường tăng luồng
        return true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(d[y[v]] == d[u] + 1) {   /// Duyệt theo thứ tự đã BFS
            if(dfs(y[v]) != 0) {    /// Tìm thấy đường mở / ĐTL
                x[u] = v, y[v] = u;
                /// Thêm cạnh u - v vào cặp ghép, tương đương với
                /// việc xóa cạnh lúc trước đã nối với u (X) và v
                /// (Y) ra khỏi cặp ghép
                return true;
            }
        }
    }
    d[u] = 1e9;     /// Không tìm thấy đường mở / ĐTL
    return false;
}

void GhepMax() {
    /// Nếu tìm thấy đường mở
    while(Find() == true) {
        for(int i = 1; i <= m; i++) {
            if(x[i] == 0)       /// Nếu i (X) chưa được ghép
                if(dfs(i))      /// Tìm được ĐM / ĐTL bắt đầu từ i (X)
                    res++;      /// Tăng số lượng cặp ghép
        }
    }

    cout << res << "\n";
    for(int i = 1; i <= m; i++)
        if(x[i] != 0)       /// Nếu i (X) được nối
            cout << i << " " << x[i] << "\n";
}

main() {
    cin >> m >> n;
    int u, v;
    while(cin >> u >> v)
        g[u].pb(v);
    GhepMax();
}
