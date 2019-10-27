#include <bits/stdc++.h>
#define maxn 300005
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

int n, q, res, x[maxn], y[maxn], st[4 * maxn], u, v;

void make_tree(int id, int l, int r) {
    if(l == r) {
        if(x[l] != y[l])
            st[id] = true;
        else
            st[id] = false;
        return;
    }
    make_tree(id*2, l, (l+r)/2);
    make_tree(id*2+1, (l+r)/2+1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int pos) {
    if(pos < l || r < pos)
        return;
    if(l == r) {
        if(x[l] != y[l])
            st[id] = true;
        else
            st[id] = false;
        return;
    }
    update(id*2, l, (l+r)/2, pos);
    update(id*2+1, (l+r)/2+1, r, pos);
    st[id] = max(st[id*2], st[id*2+1]);
}

bool get(int id, int l, int r){
    if(l == r)
        return x[l] > y[l];
    if(st[2 * id] == true)
        return get(id*2, l, (l+r)/2);
    if(st[2 * id + 1] == true)
        return get(id*2+1, (l+r)/2+1, r);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi("COMPSEQ.inp");
    fo("COMPSEQ.out");
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1; i <= n; i++)
        cin >> y[i];
    make_tree(1, 1, n);
    for(int i = 1; i <= q; i++) {
        cin >> u >> v;
        x[u] = v;
        update(1, 1, n, u);
        if(get(1, 1, n) == 0)
            cout << "N\n";
        else
            cout << "Y\n";
    }
}
