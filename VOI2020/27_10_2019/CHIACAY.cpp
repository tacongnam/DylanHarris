#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
#define pll pair <long long, long long>
#define ft first
#define sd second
#define ool 1000000000000000000
#define pb push_back
#define mp make_pair
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
using namespace std;

ll n, x, y, res, gt[10000005], gtn[10000005];
//clock_t s, f;

ll power(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a % mod;
    ll x = power(a, b / 2);
    if(b % 2 == 0)
        return (x * x) % mod;
    else
        return ((x * x) % mod * a) % mod;
}

void inp(){
    cin >> n >> x >> y;
}

void solve(){
    gt[0] = 1;
    for(int i = 1; i <= n; i++)
        gt[i] = (gt[i - 1] * i) % mod;
    gtn[n] = power(gt[n], mod - 2);
    for(int i = n - 1; i >= 1; i--)
        gtn[i] = (gtn[i + 1] * (i + 1)) % mod;
    for(int i = x; i <= n - y; i++)
        //res += iCn
        res = (res + gt[n] * (gtn[n - i] * gtn[i] % mod) % mod) % mod;
}

void out(){
    cout << res << endl;
}
main()
{
    fi("CHIACAY.inp");
    fo("CHIACAY.inp");
    inp();
    //s = clock();
    solve();
    //f = clock();
    //cout << "Solving time: " << (double) (f - s) / CLOCKS_PER_SEC << endl;
    out();
}

//10000000 1 10000000
