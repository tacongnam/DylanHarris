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

ll n, a[maxn], res, k, dp[2][maxn], st[4 * maxn], s[maxn];

void make_tree(ll id, ll l, ll r){
    if(l > r){
        st[id] = LLONG_MAX;
        return;
    }
    if(l == r){
        st[id] = a[l];
        return;
    }
    make_tree(id*2, l, (l+r)/2);
    make_tree(id*2+1, (l+r)/2+1, r);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if(v < l || r < u)
        return LLONG_MAX;
    if(u <= l && r <= v)
        return st[id];
    return min(get(id*2, l, (l+r)/2, u, v), get(id*2+1, (l+r)/2+1, r, u, v));
}

main()
{
    fi("PAY.inp");
    fo("PAY.inp");
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    make_tree(1, 1, n);
    for(ll i = 1; i <= n; i++){
        if(i < k){
            dp[0][i] = dp[0][i - 1] + a[i];
            dp[1][i] = LLONG_MAX;
        }
        else{
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + a[i];
            dp[1][i] = min(dp[0][i - k], dp[1][i - k]) + s[i] - s[i - k] - get(1, 1, n, i - k + 1, i);
        }
    }
    cout << min(dp[0][n], dp[1][n]);
}
