///....DH....///
#include <bits/stdc++.h>
#define task "BITFUN"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
#define For(i, s, n, m) for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m) for(int i = s; i >= n; i -= m)
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

const int mod = 1e9 + 7;
const int maxn = 265000;
int t, n, m, F[maxn], s[40], maxx;
int st;

map < long long, int > mp;
void sub4(long long in)
{
    mp[in] = 0;
    queue <long long> qu;
    qu.push(in);
    while(qu.size() > 0)
    {
        long long f = qu.front();
        qu.pop();
        int sta = mp[f];
        for(int i = 0; i <= log2(f); i++)
            s[i] = (f >> i) & 1;
        for(int i = log2(f) + 1; i <= 30; i++)
            s[i] = 0;
        for(int i = 0; i <= log2(f); i++)
        {
            if(s[i] == 1)
            {
                for(int j = i + 1; j <= 30; j++)
                {
                    if(s[j] == 0)
                    {
                        long long newf = f ^ (1 << i) ^ (1 << j);
                        if(newf > 1073741824)
                            break;
                        __typeof(mp.begin()) it = mp.find(newf);
                        if(it == mp.end())
                        {
                            mp[newf] = 1 - sta;
                            qu.push(newf);
                        }
                        else
                            Max(it -> second, 1 - sta);
                    }
                }
            }
        }
    }
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> t;
    sub4(3);
    sub4(7);
    sub4(15);
    memset(F, 0, sizeof(F));
    while(t--)
    {
        cin >> n;
        if(n > 100005)
        {
            memset(s, 0, sizeof(s));
            bool sub1 = true;
            for(int i = 0; i <= log2(n); i++)
                s[i] = (n >> i) & 1;
            for(int i = 1; i < log2(n); i++)
                if(s[i] != s[i - 1])
                {
                    sub1 = false;
                    break ;
                }
            if(sub1 == true)
            {
                if(s[int(log2(n))] == 1 && s[0] == 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
            {
                if(mp[n] > 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
        else
        {
            int tobit = log2(n) + 1;
            for(int i = maxx; i <= n; i++)
            {
                /// Tách các bit ra:
                for(int j = 0; j < tobit; j++)
                    s[j] = (i >> j) & 1;
                for(int j = 0; j < tobit; j++)
                {
                    if(s[j] == 1)
                    {
                        for(int k = j - 1; k >= 0; k--)
                            if(s[k] == 0)
                            {
                                /// Đổi bit thứ j, k cho nhau
                                int newt = i - (1 << j) + (1 << k);
                                F[i] = max(F[i], 1 - F[newt]);
                            }
                    }
                }
            }
            maxx = max(maxx, n);
            if(F[n] == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
