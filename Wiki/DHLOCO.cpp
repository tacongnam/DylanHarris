#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix
{
    ll val[10][10];
    ll row,col;
};
ll mod;
matrix operator * (matrix a, matrix b)
{
    matrix res;
    if(a.col != b.row)
        cout<<"ERROR!";
    for(ll i = 1; i <= a.row; i++)
        for(ll j = 1; j <= b.col; j++)
        {
            res.val[i][j] = 0;
            for(ll k = 1; k <= a.col; k++)
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j])%mod;
        }
    res.col = b.col, res.row = a.row;
    return res;
}
matrix operator ^ (matrix a, ll b)
{
    matrix res;
    res.row = a.row, res.col = a.col;
    if(b == 1)
        return a;
    res = a ^ (b/2);
    if(b % 2 == 0)
    {
        matrix ans = res * res;
        ans.col = ans.row = a.col;
        return ans;
    }
    else
    {
        matrix ans = res * res;
        ans.col = ans.row = a.col;
        ans = ans * a;
        return ans;
    }
}
matrix a,b,c;
ll n;
main()
{
    cin>>n>>mod;
    a.row = 3, a.col = 3, b.row = 3, b.col = 1;
    a.val[1][1] = 1, a.val[1][2] = 1, a.val[1][3] = 1;
    a.val[2][1] = 1, a.val[2][2] = 0, a.val[2][3] = 0;
    a.val[3][1] = 0, a.val[3][2] = 1, a.val[3][3] = 0;
    if(n == 0)
    	cout<<1;
    else if(n == 1)
    	cout<<1;
    else if(n == 2)
    	cout<<2;
	else
    {
    	c = a ^ (n-2);
    	b.val[1][1] = 2, b.val[2][1] = 1, b.val[3][1] = 1;
    	c = c * b;
    	cout<<c.val[1][1];
    }
}
