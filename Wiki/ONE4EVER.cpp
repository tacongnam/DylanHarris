#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix
{
    ll val[30][30];
    ll row, col;
};
ll mod;
ll fastm (ll a, ll b)
{
    if(b == 0)
        return 0;
    if(b == 1)
        return a;
    ll x = (fastm (a, b/2));
    if(b % 2 == 0)
        return (x * 2) %mod;
    else
        return (x * 2 + a) %mod;
}
matrix operator * (matrix a, matrix b)
{
    matrix res;
    if(a.col != b.row)
        cout << "ERROR \n";
    for(ll i = 1; i <= a.row; i++)
        for(ll j = 1; j <= b.col; j++)
    {
        res.val[i][j] = 0;
        for(ll k = 1; k <= a.col; k++)
            res.val[i][j] = (res.val[i][j] + fastm(a.val[i][k],b.val[k][j]))%mod;
    }
    res.col = b.col;
    res.row = a.row;
    return res;
}
matrix identity (matrix a)
{
    for(ll i = 1; i <= a.row; i++)
        for(ll j = 1; j <= a.col; j++)
    {
        if(i == j)
            a.val[i][j] = 1;
        else
            a.val[i][j] = 0;
    }
    return a;
}
matrix operator ^ (matrix a, ll b)
{
    if(b == 0)
        return identity(a);
    if(b == 1)
        return a;
    matrix x = a ^ (b/2);
    x.col = a.col, x.row = a.row;
    if(b % 2 == 0)
        return x * x;
    else
        return x * x * a;
}
matrix a,b,c,d;
ll g,h,k,t;
void set_ma()
{
    a.val[1][1] = g, a.val[1][2] = h;
    a.val[2][1] = 0, a.val[2][2] = 1;
    b.val[1][1] = h % mod;
    b.val[2][1] = 1;
    a.row = a.col = b.row = 2;
    b.col = 1;
}
main()
{
    cin>>t;
    while(t--)
    {
        cin>>g>>h>>mod>>k;
        set_ma();
        c = a ^ (k-1);
        d = c * b;
        cout << d.val[1][1] << endl;
    }
}
