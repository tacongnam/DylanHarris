///....DH....///
#include <bits/stdc++.h>
#define task "ARITHDIG"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<long long, long long>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
using namespace std;

template <typename R, typename D> inline void Min(R &a, D b)
{
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b)
{
    if(a<b)
        a=b;
}

long long t;
string s;

long long getdig(int id, int last, int cong, int tight, int ok)
{
    if(last == 0 & )
}

bool check(string s)
{
    if(s.size() <= 2)
        return true;
    int st = s[0], nd = s[1];
    int cong = (s[1] - s[0] + 20) % 10;
    for(int i = 2; i < s.size(); i++)
    {
        if(((s[i] - s[i - 1] + 20) % 10) != cong)
            return false;
    }
    return true;
}

long long get(string x) {
    if(x.size() == 1)
        return (x[0] - '0' + 1);
    else if(x.size() == 2) {
        long long g = (x[0] - '0') * 10 + x[1] - '0';
        return g + 1;
    }
    s = x;
    long long aa = 0;
    for(int i = 0; i <= 9; i++)
        aa += getdig(x.size() - 1, 0, i, 1, 0) - 10;
    aa += 10;
    return aa;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    fi(task".inp");
    fo(task".out");
#endif
    cin >> t;
    while(t--)
    {
        string u1, u2;
        cin >> u1 >> u2;
        long long x = get(u1), y = get(u2);
        long long ans = check(u1) ? (y - x + 1) : (y - x);
        cout << ans << "\n";
    }
}
