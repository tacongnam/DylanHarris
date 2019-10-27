#include <bits/stdc++.h>
#define maxn 1005
#define ll long long
#define mod 1000000007
#define pll pair <long long, long long>
#define ft first
#define sd second
#define ool 1000000000000000000
#define pb push_back
#define mp make_pair
#define base 29
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
using namespace std;

ll n, ahash[maxn][maxn], res, m;
string s[maxn];
vector <ll> h[maxn];

void make_hash(){
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++){
            ahash[j][i] = (ahash[j - 1][i] * base + s[j][i] - 'a' + 1) % mod;
            h[j].push_back(ahash[j][i]);
        }
    for(ll i = 1; i <= m; i++)
        sort(h[i].begin(), h[i].end());
    for(ll i = 1; i <= n; i++)
        h[0].push_back(0);
}

bool istrue(ll row){
    for(ll i = 1; i < h[row].size(); i++)
        if(h[row][i] == h[row][i - 1])
            return true;
    return false;
}

main()
{
    fi("CUTLINE.inp");
    fo("CUTLINE.inp");
    cin >> m >> n;
    for(ll i = 1; i <= m; i++) {
        cin >> s[m - i + 1];
        s[m - i + 1] = ' ' + s[m - i + 1];
    }
    make_hash();
    ll l = 0, r = m;
    while(l < r){
        ll tb = (l + r) / 2;
        if(istrue(tb) == true)
            l = tb + 1;
        else
            r = tb;
    }
    if(istrue(l) == true)
        l++;
    cout << m - l;
}
