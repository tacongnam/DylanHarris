#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct matrix {
    long long val[55][55];
    long long row, col;
};

int dinhdang(int x) {
    if(x < 0) {
        int h = x / 3;
        h = -h;
        return (x + 3 * (h + 3)) % 3;
    } else
        return x % 3;
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
            res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j]);
        res.val[i][j] = dinhdang(res.val[i][j]); //Phải có dòng này nếu không chỉ được 2 / 8 tests
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

matrix c,b;
long long n, d, t;

void initialize() {
    for(long long i = 1; i < d; i++)
        for(long long j = 1; j <= d; j++) {
            if(j - 1 == i)
                c.val[i][j] = 1;
            else
                c.val[i][j] = 0;
        }
    c.val[d][1] = 1;
    for(long long i = 2; i <= d; i++)
        c.val[d][i] = -1;
    c.row = c.col = d;
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("RECURR.inp", "r", stdin);
    freopen("RECURR.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> d;
        for(long long i = 1; i <= d; i++) {
            cin >> b.val[d - i + 1][1];
            if(b.val[d - i + 1][1] == -1)
                b.val[d - i + 1][1] = 0;
        }
        b.row = d, b.col = 1;
        initialize();
        c = c ^ (n - 1);
        c = c * b;
        for(long long i = d; i >= 1; i--)
            cout << dinhdang(c.val[i][1]) % 3 << " ";
        cout << endl;
    }
//    for(int i = 1; i <= d; i++){
//        for(int j = 1; j <= d; j++)
//            cout << c.val[i][j] << " ";
//        cout << endl;
//    }
}
