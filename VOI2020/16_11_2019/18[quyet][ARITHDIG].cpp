//???
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define V2"ARITHDIG"
#define maxn 100050
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
#define FORD(i,j,k) for(int i=j;i>=k;--i)
#define ll long long
#define endl "\n"
//#define int long long

using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//#define rand rd
int const oo=1e9+7;
int n,m,res=0;
string l,r;
vector<int> vtl,vtr;
int dp[maxn][2][2][11][11];
int calc(int pos, int ok1, int ok2,int sd, int cs,int st) /// vi tri, ok L, ok R, so du, cap so
{
    if(pos==vtr.size())
    {
//        cout<<kq<<endl;
        return 1;

    }
    if(dp[pos][ok1][ok2][sd][cs]!=-1)
        return dp[pos][ok1][ok2][sd][cs] ;
    int ma=9,mi=0;
    int re=0;
    if(ok1)
        mi=vtl[pos];
    if(ok2)
        ma=vtr[pos];
    if(st==oo||pos-st<=1)
        FOR(i,mi,ma)
    {
        if(st==oo&&i!=0) st=pos;
        re+=calc(pos+1,(ok1==1)&&(i==mi),(ok2==1)&&(i==ma),i,(i-sd+10)%10,st);
    }
    else
    {
        FOR(i,mi,ma)
        {
            if((sd+cs)%10==i)
                re+=calc(pos+1,(ok1==1)&&(i==mi),(ok2==1)&&(i==ma),i,cs,st);
        }
    }
    dp[pos][ok1][ok2][cs][sd]=re;
    return re;
}
int xl(string l,string r)
{
    vtl.clear();
    vtr.clear();
    int x=r.size()-1;
    int x1=l.size()-1;
    FORD(i,x,0)
    {
        if(x1>=0)
            vtl.pb(l[x1]-'0');
        else
            vtl.pb(0);
        vtr.pb(r[i]-'0');
        x1--;
    }
    reverse(vtl.begin(),vtl.end());
    reverse(vtr.begin(),vtr.end());
//    for(int v: vtl)
//    {
//        cout<<v<<" ";
//    }
//    cout<<endl;
//    for(int v: vtr)
//    {
//        cout<<v<<" ";
//    }
//    cout<<endl;
    memset(dp,-1,sizeof(dp));
    return calc(0,1,1,0,0,oo);
}
main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    #ifdef OK
    freopen(V2".inp", "r", stdin);
    freopen(V2".out", "w", stdout);
//    #endif // OK
    int T;
    cin>>T;
    while(T--)
    {
        cin>>l>>r;
        cout<<xl(l,r)<<endl;
    }
}
