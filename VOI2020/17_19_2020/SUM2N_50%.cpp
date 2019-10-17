#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct matrix {
    long long val[6][6];
    long long row, col;
    matrix() {
        memset(val, 0, sizeof(val));
    }
};

long long mod;

ll fastm(long long a, long long b){
    if(b == 0)
        return 0;
    if(b == 1)
        return a % mod;
    ll x = fastm(a, b/2) % mod;
    if(b % 2 == 0)
        return (x + x) % mod;
    else
        return (x + x + a) % mod;
}

matrix operator * (matrix a, matrix b) {
    matrix res;
    if(a.col != b.row)
        cout << "ERROR \n";
    for(ll i = 1; i <= a.row; i++)
        for(ll j = 1; j <= b.col; j++) {
            res.val[i][j] = 0;
            for(ll k = 1; k <= a.col; k++)
                res.val[i][j] = (res.val[i][j] + fastm(a.val[i][k], b.val[k][j])) % mod;
        }
    res.col = b.col;
    res.row = a.row;
    return res;
}

matrix identity (matrix a) {
    for(ll i = 1; i <= a.row; i++)
        for(ll j = 1; j <= a.col; j++) {
            if(i == j)
                a.val[i][j] = 1;
            else
                a.val[i][j] = 0;
        }
    return a;
}

matrix operator ^ (matrix a, ll b) {
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

matrix c, d, mx, my;
long long t;
long long a, b;

void initialize() {
    c.val[1][1] = 1, c.val[1][2] = 2, c.val[1][3] = 2;
    c.val[2][1] = 0, c.val[2][2] = 2, c.val[2][3] = 2;
    c.val[3][1] = 0, c.val[3][2] = 0, c.val[3][3] = 2;
    c.row = c.col = 3;
    d.val[1][1] = 1, d.val[2][1] = 1, d.val[3][1] = 1;
    d.row = 3, d.col = 1;
}

main() {
    //freopen("SUM2N.inp", "r", stdin);
    //freopen("SUM2N.out", "w", stdout);
    while(cin >> a >> mod) {
        initialize();
        mx = c ^ (a - 1);
        //[a, b]
        mx = mx * d;
        cout << (mx.val[1][1]) % mod;
        cout << "\n";
    }
//    for(ll i = 1; i <= d; i++){
//        for(ll j = 1; j <= d; j++)
//            cout << c.val[i][j] << " ";
//        cout << endl;
//    }
}
