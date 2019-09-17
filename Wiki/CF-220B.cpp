#include <bits/stdc++.h>
#define pii pair<int,int>
#define mod 1000000007
#define ll long long
#define ft first
#define sd second
#define For(a,b,c) for(int i = a; i <= b; i += c)
#define Ford(a,b,c) for(int i = a; i >= b; i -= c)
 
#define maxn 100005
 
using namespace std;
 
int n, a[100005], cnt[100005], ans[100005], qu, s, k, res;
 
struct Query
{
    int l, r, in, l1;
    bool operator < (const Query &P){
        return ((l1 < P.l1) || (l1 == P.l1 && r < P.r));
    }
} q[100005];
 
void add(int pos){
    if(a[pos] > n)
        return;
    cnt[a[pos]]++;
    if(cnt[a[pos]] == a[pos])
        res++;
    if(cnt[a[pos]] == a[pos]+1)
        res--;
}
 
void remov(int pos){
    if(a[pos] > n)
        return;
    cnt[a[pos]]--;
    if(cnt[a[pos]] == a[pos])
        res++;
    if(cnt[a[pos]] == a[pos]-1)
        res--;
}
void solve(){
    int curl = 0, curr = 0;
    for(int i = 1; i <= qu; i++){
        while(curl < q[i].l)
            remov(curl++);
        while(curl > q[i].l){
            add(--curl);
        }
        while(curr < q[i].r){
            add(++curr);
        }
        while(curr > q[i].r){
            remov(curr--);
        }
        ans[q[i].in] = res;
    }
}
 
main(){
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d", &n, &qu);
    s = sqrt(n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= qu; i++){
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].in = i;
        q[i].l1 = q[i].l / s;
    }
    sort(q + 1, q + qu + 1);
    cnt[0] = 1e9;
    solve();
    for(int i = 1; i <= qu; i++)
        printf("%d\n", ans[i]);
}
