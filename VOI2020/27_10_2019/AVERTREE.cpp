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

ll n, a[maxn], res, s[maxn], k, bit[maxn], arr[maxn];
vector <ll> st;
void update(ll id){
    for(; id <= maxn; id += (id & (-id)))
        bit[id]++;
}

ll get(ll id){
    ll ans = 0;
    for(; id > 0; id -= (id & (-id)))
        ans += bit[id];
    return ans;
}

void compress(){
    vector < pair<ll, ll> > vtp;
    for(ll i = 0; i <= n; i++)
        vtp.push_back({arr[i], i});
    sort(vtp.begin(), vtp.end());
    ll dem = 0;
    for(ll i = 0; i <= n; i++){
        if(i != 0 && vtp[i].first == vtp[i - 1].first)
            arr[vtp[i].second] = dem;
        else
            arr[vtp[i].second] = ++dem;
    }
}

main () {
    fi("AVERTREE.inp");
    fo("AVERTREE.out");
    cin >> n >> k;
    arr[0] = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        arr[i] = s[i] - i * k;
    }
    compress();
    res = 0;
    for(ll i = 1; i <= n; i++) {
        update(arr[i - 1]);
        res += get(arr[i]);
    }
    cout << res;
}
