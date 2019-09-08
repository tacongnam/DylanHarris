#include <bits/stdc++.h>
#define pii pair<int,int>
#define mod 1000000007
#define ll long long
#define ft first
#define sd second

#define maxn 100005

using namespace std;

int n, a[maxn];
vector <int> st[4 * maxn];

void make_st(int id, int l, int r){
    if(l > r)
        return;
    if(l == r){
        st[id].push_back(a[l]);
        return;
    }
    make_st(id*2, l, (l+r)/2);
    make_st(id*2+1, (l+r)/2+1, r);
    merge(st[id*2].begin(), st[id*2].end(), st[id*2+1].begin(), st[id*2+1].end(), back_inserter(st[id]));
}

int get(int id, int l, int r, int u, int v, int val){
    if(r < u || v < l)
        return 0;
    if(u <= l && r <= v)
        return st[id].end() - upper_bound(st[id].begin(), st[id].end(), val);
    int a = get(id*2, l, (l+r)/2, u, v, val);
    int b = get(id*2+1, (l+r)/2+1, r, u, v, val);
    return a + b;
}

main(){
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    make_st(1, 1, n);
    int m, kq = 0, a1, b, c;
    cin >> m;
    while(m--){
        cin >> a1 >> b >> c;
        kq = get(1, 1, n, a1 ^ kq, b ^ kq, c ^ kq);
        cout << kq << endl;
    }
}
