#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define MOD 1000000007
//#define f first
//#define s second
//#define int long long
#define N 300005
using namespace std;
int n;
int res = 0;
long long a[N];
//priority_queue < long long > pq;
deque < long long > dq;
void solve()
{
    sort(a + 1, a + n + 1);
    int pos = n;
    while(1)
    {
        if(dq.size())
        {
            long long x = max(dq[0] , a[pos]);
            while(pos >= 1 && a[pos] == x)
                pos --;
            while(dq.size() && dq[0] == x)
                dq.pop_front();
            if(pos == 0 && dq.size() == 0)
                break;
            dq.push_back(x/2);
            res ++;
        }
        else
        {
            dq.push_back(a[pos --]);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("UNION.inp","r",stdin);
    freopen("UNION.out","w",stdout);
    cin >> n;
//    scanf("%lld", &n);
    FOR(i, 1, n)
    {
        cin >> a[i];
//        scanf("%lld", &a[i]);
    }
    solve();
    cout << res;
//    printf("%d", res);
}
