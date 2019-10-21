#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

struct oxy {
    int x, y;
    double operator ^ (const oxy &P) {
        return min(abs(double(P.x - x)), abs(double(P.y - y)));
    }
} a[maxn];
vector <double> vt;
int n, k, dp[maxn];

void sub1() {
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++)
            vt.push_back(a[i] ^ a[j]);
    }
    sort(vt.begin(), vt.end());
    cout << vt[k - 1];
}

void sub2(oxy maxx, oxy minn){
    //Xem p, q bang bao nhieu
    int row = maxx.y - minn.y + 1;
    int col = maxx.x - minn.x + 1;
    dp[0] = ((row + col - 1) * row * col)/ 2;
    for(int i = 1; i <= n; i++)
        dp[i] = (((row + col) - (2 * (i - 1) + 1) * 2) * row * col);
    for(int i = 0; i <= n; i++){
        if(dp[i] >= k){
            cout << i;
            return;
        }
        else
            k -= dp[i];
    }
}

main(){
    //freopen("DIST.inp", "r", stdin);
    //freopen("DIST.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    oxy minn = {INT_MAX, INT_MAX}, maxx = {-INT_MAX, -INT_MAX};
    for(int i = 1; i <= n; i++){
        minn.x = min(minn.x, a[i].x);
        minn.y = min(minn.y, a[i].y);
        maxx.x = max(maxx.x, a[i].x);
        maxx.y = max(maxx.y, a[i].y);
    }
    int row = maxx.y - minn.y + 1;
    int col = maxx.x - minn.x + 1;
    if(row * col == n)
        sub2(maxx, minn);
    else sub1();
}
