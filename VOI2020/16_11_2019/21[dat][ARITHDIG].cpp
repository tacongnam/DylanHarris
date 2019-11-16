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
int T;
vector < int > a;
long long dp[100005][3][12][12];
long long calc(int pos, bool ok, int lval, int ar)
{
    if(pos == a.size() || ok == 0)
        return dp[pos][ok][lval][ar] = 1;
    if(dp[pos][ok][lval][ar] != -1)
        return dp[pos][ok][lval][ar];
    long long sum = 0;
    int x = (lval + ar) % 10;
    if(ok && a[pos] >= x)
    {
        sum += calc(pos + 1, (a[pos] == x), x, ar);
    }
    return dp[pos][ok][lval][ar] = sum;
}
void ptich(string s)
{
    a.clear();
    for(int i = 0; i < s.size(); i ++)
    {
        a.push_back(s[i] - '0');
    }
}
long long solve(string s)
{
    if(s.size() == 1)
    {
        return (s[0] - '0') - 0;
    }
    memset(dp, -1, sizeof(dp));
    ptich(s);
    long long sum = 0;
    FOR(i, 0, 9)
    {
        FOR(j, 1, a[0] - 1) sum += calc(1, 0, j, i);
        sum += calc(1, 1, a[0], i);
    }
    sum += (a.size() - 2) * 90 + 9;
    return sum;
}
bool check(string s)
{
    if(s.size() == 1)
        return 1;
    int ar = (s[1] - s[0] + 10) % 10;
    for(int i = 0; i < s.size() - 1; i ++)
    {
        if((s[i] + ar - '0')% 10 != (s[i + 1] - '0'))
            return 0;
    }
    return 1;
}
string l, r;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ARITHDIG.inp","r",stdin);
    freopen("ARITHDIG.out","w",stdout);
    cin >> T;
    while(T --)
    {
        cin >> l;
        cin >> r;
//        cout << solve(r) << "\n";
//        cout << solve(l) << "\n";
//        cout << check(l) << "\n";
        cout << solve(r) - solve(l) + check(l) << "\n";
    }
}
