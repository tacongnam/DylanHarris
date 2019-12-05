///------------------  ONESHOTAC -------------------
#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
const int N = 200005;
const int BASE = 100000;
int dp[128805][3], a[100005], d = 0, T, n, x0, x = 0;
void cs(int s, int i, int k, int p)
{
    if(k > p)
    {
        if(s > BASE && s <= 1073741824) a[++d] = s;
        return;
    }
    for(; i < 31; ++i) cs(s+(1<<i), i+1, k+1, p);
}
void xl(int i)
{
    int p;
    if(i > BASE || __builtin_popcount(i) < 5) p = 31;
    else p = 17;
    if(i > BASE) n = a[i-BASE];
    else n = i;
    if(!dp[i][0]) return;
    if(dp[i][1] == dp[i][0]) dp[i][2] = 1, dp[i][1] = 0;
    else if(dp[i][2] == dp[i][0]) dp[i][1] = 1, dp[i][2] = 0;
    else if(dp[i][1]+dp[i][2] != dp[i][0]*2) dp[i][1] = dp[i][2] = 1;
    else dp[i][1] = dp[i][2] = 0;
    for(int j1 = 0; j1 < p; ++j1)
        if((n>>j1)&1)
        {
            x0 = n - (1<<j1);
            for(int j2 = j1+1; j2 < p; ++j2)
                if(!((n>>j2)&1))
                {
                    x = x0 + (1<<j2);
                    if(x > BASE)
                    {
                        int k = lower_bound(a+1, a+d+1, x) - a;
                        if(a[k] != x) continue;
                        x = k + BASE;
                    }
                    dp[x][0]++;
                    dp[x][1] += dp[i][1];
                    dp[x][2] += dp[i][2];
                }
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BITFUN.inp","r",stdin);
    freopen("BITFUN.out","w",stdout);
    for(int i = 0; i < 30; ++i)
    {
        x += (1<<i);
        if(x < (BASE + 1)) dp[x][0] = dp[x][1] = 1;
        else a[++d] = x;
        if(i < 4) cs(0, 0, 1, i+1);
    }
    sort(a+1, a+d+1);
    for(int i = 1; i < BASE + d; ++i) xl(i);
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        if(n > BASE) n = BASE + lower_bound(a+1, a+d+1, n) - a;
        if(dp[n][1] && dp[n][2]) printf("YES\n");
        else if(!dp[n][1] && !dp[n][2]) printf("NO\n");
        else if(dp[n][1]) printf("YES\n");
        else printf("NO\n");
    }
}
