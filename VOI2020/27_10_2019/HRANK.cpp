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
#define ll_MAX LLONG_MAX
using namespace std;

ll n, a[maxn], res, i, ans[maxn];

struct Node{
    ll val, down;
} st[4 * maxn];

void lazy(ll id){
    st[id*2].down += st[id].down;
    st[id*2 + 1].down += st[id].down;
    st[id*2].val -= st[id].down;
    st[id*2+1].val -= st[id].down;
    st[id].down = 0;
}

void make_tree(ll id, ll l, ll r){
    if(l > r){
        st[id].val = ll_MAX;
        return;
    }
    if(l == r){
        st[id].val = a[l];
        st[id].down = 0;
        return;
    }
    make_tree(id*2, l, (l+r)/2);
    make_tree(id*2+1, (l+r)/2+1, r);
    st[id].val = min(st[id * 2].val, st[id * 2 + 1].val);
}

void update1 (ll id, ll l, ll r, ll pos){
    if(pos < l || pos > r)
        return;
    if(l == r){
        st[id].val = ll_MAX;
        st[id].down = -1;
        return;
    }
    lazy(id);
    update1(id*2, l, (l+r)/2, pos);
    update1(id*2+1, (l+r)/2+1, r, pos);
    st[id].val = min(st[id * 2].val, st[id * 2 + 1].val);
}

void update2 (ll id, ll l, ll r, ll u, ll v){
    if(r < u || v < l)
        return;
    if(u <= l && r <= v){
        st[id].val--;
        st[id].down++;
        return;
    }
    lazy(id);
    update2(id*2, l, (l+r)/2, u, v);
    update2(id*2+1, (l+r)/2+1, r, u, v);
    st[id].val = min(st[id * 2].val, st[id * 2 + 1].val);
}

ll get(ll id, ll l, ll r){
    if(l == r)
        return l;
    lazy(id);
    if(st[id*2+1].val == 0)
        return get(id*2+1, (l+r)/2+1, r);
    else if(st[id*2].val == 0)
         return get(id*2, l, (l+r)/2);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi("HRANK.inp");
    fo("HRANK.inp");
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    make_tree(1, 1, n);
    ll cnt = n;
    for(ll i = 1; i <= n; i++){
        ll g = get(1, 1, n);
        ans[g] = cnt--;
        update1(1, 1, n, g);
        update2(1, 1, n, g + 1, n);
    }
    for(ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
