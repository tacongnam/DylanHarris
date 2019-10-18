				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN "dbg"
using namespace std;
const int N = 1005;
int n , a , b ,c , d, dem;
pair <int , int> h[N];
bool dd[N];
long long ans, maxx = 1e18, p;
void sub12()
{
    sort( h+1 , h+1+n);
    for (int i = 0 ; i <= b - a - p; i++){
    do {
    dem = a + i;
    ans = 0;
    for (int i = 1; i <= n; i++){
        dem += h[i].f;
        ans += 1ll* abs(d - dem) * h[i].s;
        if (ans > maxx) break;
    }
    maxx = min(maxx, ans);
    }while (next_permutation(h+1,h+1+n));
    }
    cout <<maxx;

}
bool cmp( pair <int , int > a , pair <int , int> b)
{
    return (1ll*a.f*b.s < 1ll*b.f*a.s);
}
bool cmpp( pair <int , int > a , pair <int , int> b)
{
    return (1ll*a.s*b.f > 1ll*b.s*a.f);
}
void sub3()
{
    sort( h+1 , h+1+n, cmp);
    dem = a;
    for (int i = 1 ; i <= n; i++)
    {
        dem += h[i].f;
        ans += 1ll*abs(dem - d)*h[i].s;
    }
    cout <<ans;
}

void sub4()
{
    sort(h+1 , h+1+n , cmp);
        dem = b;
        for (int i = 1; i <= n; i++)
        {
            ans += 1ll*abs(dem-d)*h[i].s;
            dem -= h[i].f;
        }
    cout <<ans;
}

void duyet(int i , int st, int fn , long long sum)
{
    if (i > n){
        maxx = min(maxx , sum);
        return;
    }

    if ( fn + h[i].f <= b) duyet(i+1 , st, fn + h[i].f , sum + 1ll*abs(fn + h[i].f - d)* h[i].s);
    if ( st - h[i].f >= a) duyet(i+1 , st - h[i].f , fn , sum+ 1ll*abs(st - d) * h[i].s);
}

void sub56()
{
    sort(h+1, h+1+n , cmpp);
    for (int i = d-100 ; i <= d+100; i++)
        if (i >= a && i + h[1].f <= b) duyet(2 , i , i + h[1].f , 1ll*abs( i + h[1].f - d)*h[1].s );
    cout <<maxx;
}

void sub7()
{
    sort(h+1, h + 1 + n , cmp);
    for (int i = d - 10000 ; i <= d + 10000; ++i) if (i >= a && i + h[1].f <= b)
    {
        long long res = 0;
        int st = i;
        int fn = i + h[1].f;
        bool ch = 1;
        res += 1ll*abs(d-fn)*h[1].s;
        for (int j = 2 ; j <= n; ++j){
            if (st - h[j].f >= a && (1ll*abs(d-fn-h[j].f)*h[j].s > 1ll*abs(d-st)*h[j].s || fn + h[j].f > b)){
                res += 1ll*abs(d-st)*h[j].s;
                st -= h[j].f;
            }
            else if (fn + h[j].f <= b) {
                fn += h[j].f;
                res += 1ll*abs(d-fn)*h[j].s;
            }
            else {
                ch = 0;
                break;
            }
        }
        if (ch) maxx = min(maxx, res);
    }
    cout <<maxx;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);
	cin >> n >> a >> b >> d;
    for (int i = 1; i <= n ; i++) cin >> h[i].f >> h[i].s, p+= h[i].f;
    /*if (n <= 8) sub12();
    else if (a==d) sub3();
    else if (b==d) sub4();
    else if (n <= 20) sub56();
    else*/
        sub7();
}
