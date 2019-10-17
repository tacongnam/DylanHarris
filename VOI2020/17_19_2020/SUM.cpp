#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

struct matrix {
    long long val[6][6];
    long long row, col;
    matrix(){
        memset(val, 0, sizeof(val));
    }
};

matrix operator * (matrix a, matrix b) {
    matrix res;
    if(a.col != b.row)
        cout << "ERROR \n";
    for(ll i = 1; i <= a.row; i++)
        for(ll j = 1; j <= b.col; j++) {
            res.val[i][j] = 0;
            for(ll k = 1; k <= a.col; k++)
                res.val[i][j] = (res.val[i][j] + (a.val[i][k] * b.val[k][j]) % mod) % mod;
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
double a, b;

void initialize() {
    c.val[1][1] = 1, c.val[1][2] = 1, c.val[1][3] = 2, c.val[1][4] = 1;
    c.val[2][1] = 0, c.val[2][2] = 1, c.val[2][3] = 2, c.val[2][4] = 1;
    c.val[3][1] = 0, c.val[3][2] = 0, c.val[3][3] = 1, c.val[3][4] = 1;
    c.val[4][1] = 0, c.val[4][2] = 0, c.val[4][3] = 0, c.val[4][4] = 1;
    c.row = c.col = 4;
    d.val[1][1] = 0, d.val[2][1] = 0, d.val[3][1] = 0, d.val[4][1] = 1;
    d.row = 4, d.col = 1;
}

main() {
    freopen("SUM.inp", "r", stdin);
    freopen("SUM.out", "w", stdout);
    initialize();
    cin >> a >> b;
    if(a > (long long)(a))
        mx = c ^ (long long)(a);
    else
        mx = c ^ (long long)(a - 1);
    //[a, b]
    my = c ^ (long long)(b + 1);
    mx = mx * d;
    my = my * d;
    cout << (my.val[1][1] - my.val[2][1] - mx.val[1][1] + 1000 * (long long) mod) % mod;
    cout << endl;
//    for(ll i = 1; i <= d; i++){
//        for(ll j = 1; j <= d; j++)
//            cout << c.val[i][j] << " ";
//        cout << endl;
//    }
}
