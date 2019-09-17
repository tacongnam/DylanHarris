#include <bits/stdc++.h>
#define maxn 100005
#define maxa 100005
using namespace std;
 
int pos[maxn], counter, beginpos[maxn], endpos[maxn], u, v; //Phục vụ cho dfs
int cnt[maxn], res[maxn], ans[maxn]; //Phục vụ cho tính query
int c[maxn], n, numquery, s; //Phục vụ nhập dữ liệu
vector <int> g[maxn];
//cnt là biến đếm số lần xuất hiện của màu c[u]
struct QUERY {
    int l, r, in, l1, k;
    bool operator < (const QUERY &P) {
        return ((l1 < P.l1) || (l1 == P.l1 && r < P.r));
    }
} q[maxn];
 
void dfs(int u, int p) {
    pos[++counter] = c[u]; //Lưu lại chỉ số của nút tương ứng trên mảng eulertour
    beginpos[u] = counter; //Lưu lại chỉ số của các nút mà u bắt đầu quản lý trên eulertour
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != p)
            dfs(v, u);		//dfs bình thường
    }
    endpos[u] = counter; //Lưu lại chỉ số của các nút mà u kết thúc quản lý trên eulertour
}
 
main() {
    scanf("%d%d", &n, &numquery);
    s = sqrt(n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= numquery; i++) {
        scanf("%d%d", &v, &u);
        q[i] = {beginpos[v], endpos[v], i, beginpos[v] / s, u};
    }
    sort(q + 1, q + numquery + 1);
    int curl = 1, curr = 1; //Hai con trỏ đang ở vị trí 1
    cnt[pos[1]] = 1; //Màu tương ứng với vị trí 1 đang được chọn
    res[1] = 1; //Có 1 màu xuất hiện 1 lần (màu ở vị trí 1)
    for(int i = 1; i <= numquery; i++) {
        for(; curl < q[i].l; curl++)
            res[cnt[pos[curl]]--]--; //Giảm res[k+1] di 1
        for(; curl > q[i].l;) {
            curl--;
            res[++cnt[pos[curl]]]++; //Từ đó tăng res[k] lên 1
        }
        for(; curr < q[i].r;) {
            curr++;
            res[++cnt[pos[curr]]]++; //Từ đó tăng res[k] lên 1
        }
        for(; curr > q[i].r; curr--)
            res[cnt[pos[curr]]--]--; //Giảm res[k+1] di 1
        ans[q[i].in] = res[q[i].k];
    }
    for(int i = 1; i <= numquery; i++)
        printf("%d\n", ans[i]);
}
