//Problem:  https://codeforces.com/gym/248817/problem/N
#include <bits/stdc++.h>
#define maxn 70
using namespace std;
long long m, n, k, a[maxn][maxn], b[maxn][maxn], dp[maxn][maxn][maxn][maxn], res;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("HTAB.inp", "r", stdin);
    freopen("HTAB.out", "w", stdout);
    cin >> m >> n >> k;
    for(long long i = 1; i <= m; i++)
        for(long long j = 1; j <= n; j++)
            cin >> a[i][j];
    for(long long i = 1; i <= m; i++)
        for(long long j = 1; j <= n; j++)
            cin >> b[i][j];
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j <= n; j++) //Compare column i of A and j of B
            for(long long x = m; x > 0; x--)
                for(long long y = m; y > 0; y--)
                    if(abs(b[y][j] - a[x][i]) <= k)
                        dp[i][j][x][y] = dp[i][j][x + 1][y + 1] + 1;
                    else
                        dp[i][j][x][y] = 0;
    for(long long i = 1; i <= m; i++)
        for(long long j = 1; j <= n; j++)
            for(long long x = 1; x <= m; x++)
                for(long long y = 1; y <= n; y++){ //Two table at (i, j) A and (x, y) B
                    long long minn = INT_MAX;
                    for(long long l = j; l <= n; l++){
                        if(y + (l - j) > n)
                            break;
                        if(dp[l][y + (l - j)][i][x] == 0)
                            break;
                        minn = min(minn, dp[l][y + (l - j)][i][x]);
                        res = max(res, minn * (l - j + 1));
                    }
                }
    cout << res;
//    for(long long i = 1; i <= n; i++)
//    for(long long j = 1; j <= n; j++)
//    for(long long x = 1; x <= m; x++)
//    for(long long y = 1; y <= m; y++){
//        cout << "TABLE A: (" << x << ";" << i << ") TABLE B: (" << y << ";" << j << ") ";
//        cout << dp[i][j][x][y] << "\n";
//    }
}
 
/*
3 3 1
1 1 1 1 1 1 1 1 2
2 2 2 2 1 1 2 1 1
*/
