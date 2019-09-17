#include <bits/stdc++.h>
#define pii pair<int,int>
#define mod 1000000007
#define ll long long
#define ft first
#define sd second
#define For(a,b,c) for(int i = a; i <= b; i += c)
#define Ford(a,b,c) for(int i = a; i >= b; i -= c)
 
#define maxn 200005
 
using namespace std;
 
long long n, a[200005], cnt[1000005], ans[200005], qu, s, k, res;
 
struct Query{
    long long l, r, in, l1;
    bool operator < (const Query &P){
        return ((l1 < P.l1) || (l1 == P.l1 && r < P.r));
    }
} q[maxn];
 
main(){
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%lld%lld", &n, &qu);
    s = sqrt(n);
    for(long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(long long i = 1; i <= qu; i++){
        scanf("%lld%lld", &q[i].l, &q[i].r);
        q[i].in = i;
        q[i].l1 = q[i].l / s;
    }
    sort(q + 1, q + qu + 1);
    long long curl = 1, curr = 1;
    cnt[a[1]]++;
    res = a[1];
    for(long long i = 1; i <= qu; i++){
        while(curl < q[i].l){
            res -= cnt[a[curl]] * cnt[a[curl]] * a[curl];
            cnt[a[curl]]--;
            res += cnt[a[curl]] * cnt[a[curl]] * a[curl];
            curl++;
        }
        while(curl > q[i].l){
            curl--;
            res -= cnt[a[curl]] * cnt[a[curl]] * a[curl];
            cnt[a[curl]]++;
            res += cnt[a[curl]] * cnt[a[curl]] * a[curl];
        }
        while(curr < q[i].r){
            curr++;
            res -= cnt[a[curr]] * cnt[a[curr]] * a[curr];
            cnt[a[curr]]++;
            res += cnt[a[curr]] * cnt[a[curr]] * a[curr];
        }
        while(curr > q[i].r){
            res -= cnt[a[curr]] * cnt[a[curr]] * a[curr];
            cnt[a[curr]]--;
            res += cnt[a[curr]] * cnt[a[curr]] * a[curr];
            curr--;
        }
        ans[q[i].in] = res;
    }
    for(long long i = 1; i <= qu; i++)
        printf("%lld\n", ans[i]);
}
