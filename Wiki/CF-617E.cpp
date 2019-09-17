#include <bits/stdc++.h>
#define pii pair<int,int>
#define mod 1000000007
#define ll long long
#define ft first
#define sd second
#define For(a,b,c) for(int i = a; i <= b; i += c)
#define Ford(a,b,c) for(int i = a; i >= b; i -= c)
#define int long long
#define maxn 1000005
 
using namespace std;
 
int n, k, qu, ans[1000005], cnt[2000005], res, s, sum[1000005], a[1000005];
 
struct query{
    int l, r, in, l1;
    bool operator < (const query &P){
        return ((l1 < P.l1) || (l1 == P.l1 && r < P.r));
    }
} q[maxn];
 
void add(int pos){
    res += cnt[sum[pos] ^ k];
    cnt[sum[pos]]++;
}
 
void remov(int pos){
    cnt[sum[pos]]--;
    res -= cnt[sum[pos] ^ k];
}
 
void solve(){
    int curl = 1, curr = 0;
    cnt[0] = 1;
    for(int i = 1; i <= qu; i++){
        while(curl < q[i].l){
            remov(curl - 1);
            curl++;
        }
        while(curl > q[i].l){
            curl--;
            add(curl - 1);
        }
        while(curr < q[i].r)
            add(++curr);
        while(curr > q[i].r)
            remov(curr--);
        ans[q[i].in] = res;
    }
}
main(){
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%lld%lld%lld", &n, &qu, &k);
    s = sqrt(n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] ^ a[i];
    }
    for(int i = 1; i <= qu; i++){
        scanf("%lld%lld", &q[i].l, &q[i].r);
        q[i].in = i;
        q[i].l1 = q[i].l / s;
    }
    sort(q + 1, q + qu + 1);
    solve();
    for(int i = 1; i <= qu; i++)
        printf("%lld\n", ans[i]);
}
