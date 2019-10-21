#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;

ll n, a[maxn], s[maxn], k;
bool check(ll x){
    ll dem = 0, pos = n;
    while(a[pos] >= x){
        dem++;
        pos--;
    }
    //Phan nhung mon qua con lai vao cac hop
    return ((s[pos] / x + dem) >= k);
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("GROUP.inp", "r", stdin);
    freopen("GROUP.out", "w", stdout);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    ll l = 1, r = 1e18;
    while(l < r){
        ll tb = (l + r) / 2;
        if(check(tb) == false)
            r = tb;
        else
            l = tb + 1;
    }
    if(check(l) == false)
        l--;
    cout << l;
}
