///....DH....///
/// AC

#include <bits/stdc++.h>
#define task                "SEGMENTS"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 105;

int n, m, q, a[maxn], b[maxn], c[maxn], d[maxn];
int vi[maxn][maxn], wall[maxn][maxn][5];
long long no, val[maxn][maxn];
vector <long long> ans;

void calcwall() {
    For(i, 1, m, 1) {
        For(j, 1, n, 1) {
            wall[i][j][1] = wall[i][j][2] = wall[i][j][3] = wall[i][j][4] = 1;
            /// Kiểm tra ô [i, j] - chặn bởi đường thẳng
            For(k, 1, q, 1) {
                /** up **/
                if(b[k] == d[k] && b[k] == i && j > a[k] && j <= c[k])
                    wall[i][j][1] = 0;
                else
                    Min(wall[i][j][1], 1);
                /** left **/
                if(a[k] == c[k] && a[k] == j - 1 && i > b[k] && i <= d[k])
                    wall[i][j][2] = 0;
                else
                    Min(wall[i][j][2], 1);
                /** down **/
                if(b[k] == d[k] && b[k] == i - 1 && j > a[k] && j <= c[k])
                    wall[i][j][3] = 0;
                else
                    Min(wall[i][j][3], 1);
                /** right **/
                if(a[k] == c[k] && a[k] == j && i > b[k] && i <= d[k])
                    wall[i][j][4] = 0;
                else
                    Min(wall[i][j][4], 1);
            }
            /// Kiểm tra ô [i, j] - chặn bởi bảng
            if(i == m)
                wall[i][j][1] = 0;
            if(j == 1)
                wall[i][j][2] = 0;
            if(i == 1)
                wall[i][j][3] = 0;
            if(j == n)
                wall[i][j][4] = 0;
        }
    }
    return ;
}

void loang(int x1, int y1) {
    no += val[x1][y1];
    vi[x1][y1] = 1;
    if(wall[x1][y1][1] == 1 && vi[x1 + 1][y1] == 0)
        loang(x1 + 1, y1);
    if(wall[x1][y1][2] == 1 && vi[x1][y1 - 1] == 0)
        loang(x1, y1 - 1);
    if(wall[x1][y1][3] == 1 && vi[x1 - 1][y1] == 0)
        loang(x1 - 1, y1);
    if(wall[x1][y1][4] == 1 && vi[x1][y1 + 1] == 0)
        loang(x1, y1 + 1);
    return ;
}

map <int, int> mpx, mpy;
vector <int> mpxx, mpyy;

int len[maxn], wei[maxn];

void compress() {
    mpyy.pb(m), mpyy.pb(0), mpyy.pb(INT_MAX);
    mpxx.pb(n), mpxx.pb(0), mpxx.pb(INT_MAX);
    sort(mpxx.begin(), mpxx.end());
    sort(mpyy.begin(), mpyy.end());
    int cnt = 0;
    For(i, 0, mpxx.size() - 2, 1) {
        if(mpxx[i] < n && mpxx[i + 1] != mpxx[i])
            wei[cnt + 1] = mpxx[i + 1] - mpxx[i]; /// Độ dài của ô
        if(mpxx[i] != mpxx[i + 1])
            mpx[mpxx[i]] = cnt, cnt++;
    }
    n = cnt;
    cnt = 0;
    For(i, 0, mpyy.size() - 2, 1) {
        if(mpyy[i] < m && mpyy[i + 1] != mpyy[i])
            len[cnt + 1] = mpyy[i + 1] - mpyy[i]; ///Chiều dài của ô
        if(mpyy[i] != mpyy[i + 1])
            mpy[mpyy[i]] = cnt, cnt++;
    }
    m = cnt;
    n--, m--;
    For(i, 1, m, 1)
        For(j, 1, n, 1)
            val[i][j] = 1ll * wei[j] * len[i];  /// Giá trị thực của ô
}

void mergewseg() {  /// Gán toạ độ mới cho đường thẳng
    For(i, 1, q, 1) {
        a[i] = mpx[a[i]];
        c[i] = mpx[c[i]];
        b[i] = mpy[b[i]];
        d[i] = mpy[d[i]];
    }
}

void inp_preprocess() {
    cin >> n >> m;
    cin >> q;
    For(i, 1, q, 1) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if(a[i] == c[i] && b[i] == d[i]) {
            i--, q--;
            continue;
        }
        if(a[i] == c[i]) {
            if(d[i] < b[i])
                swap(d[i], b[i]);
            if(a[i] <= 0 || a[i] >= n || b[i] >= m || d[i] <= 0) {
                i--, q--;
                continue;
            }
            if(b[i] < 0)
                b[i] = 0;
            if(d[i] > m)
                d[i] = m;
            mpxx.pb(a[i]);
            mpyy.pb(b[i]), mpyy.pb(d[i]);
        }
        if(b[i] == d[i]) {
            if(a[i] > c[i])
                swap(a[i], c[i]);
            if(b[i] <= 0 || b[i] >= m || a[i] >= n || c[i] <= 0) {
                i--, q--;
                continue;
            }
            if(a[i] < 0)
                a[i] = 0;
            if(c[i] > n)
                c[i] = n;
            mpyy.pb(b[i]);
            mpxx.pb(a[i]), mpxx.pb(c[i]);
        }
    }
}

void solve() {
    For(i, 1, m, 1)
        For(j, 1, n, 1)
            if(vi[i][j] == 0) {
                no = 0;
                loang(i, j);
                ans.push_back(no);
            }
    sort(ans.begin(), ans.end());
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << "\n";
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    inp_preprocess();   /// nhập vào và tiền xử lý
    compress();         /// nén toạ độ đường thẳng
    mergewseg();        /// gán toạ độ mới
    calcwall();         /// tính khả năng đi được
    solve();            /// giải bài toán và in kết quả
}
