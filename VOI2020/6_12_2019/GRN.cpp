///....DH....///
#include <bits/stdc++.h>
#define task "GRN"
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
const int maxn = 1000005;

int n, a[maxn * 2], d[maxn * 2];
long long dem;
bool nt[2000005];
vector <int> vt;
void snt() {
    nt[0] = true, nt[1] = true;
    for(int i = 2; i <= 1000; i++) {
        if(nt[i] == false) {
            vt.pb(i);
            for(int j = i; j <= 1000000; j += i)
                nt[j] = true;
        }
    }
    for(int i = 10000; i <= 1000000; i++)
        if(nt[i] == false)
            vt.pb(i);
}

void sub4() {
    snt();
    int nn = n, cnt = 0;
    for(int i = 0; i < vt.size(); i++) {
        if(nn % vt[i] == 0) {
            d[++cnt] = 0;
            while(nn % vt[i] == 0)
                d[cnt]++, nn /= vt[i];
        }
    }
    dem = 1;
    for(int i = 2; i <= cnt; i++)
        dem *= 1ll * (d[i] + 1);
    dem *= d[1];
    cout << dem;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n;
    for(int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    n *= 2;
    if(n > 2000) {
        sub4();
        return 0;
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++)
    {
        /// set tất cả các mảng bằng 0
        for(int j = 2; j <= n; j++)
            d[j] = 0;
        d[i] = 1;
        int last = 2, dist = a[i] - a[1], no = 2;
        while(last <= n)
        {
            if(d[last] == 0)
            {
                int h = lower_bound(a + 1, a + n + 1, a[last] + dist) - a;
                if(a[h] == a[last] + dist && h != n + 1)
                    d[h] = 1, no += 2;
                else
                    break;
            }
            last++;
        }
        if(no == n)
            dem++;
    }
    cout << dem;
    return 0;
//    }
}
