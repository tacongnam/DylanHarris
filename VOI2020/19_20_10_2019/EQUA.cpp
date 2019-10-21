#include <bits/stdc++.h>
using namespace std;

vector <double> vt;
double a, b, c;
int n, cnt, vs;

void solve(double a, double b, double c) {
    if(a == 0 && b != 0)
        vt.push_back(double(-c / b));
    else if(a != 0) {
        double d = b * b - 4 * a * c;
        if(d > 0) {
            double x1 = (- b + sqrt(d)) / (2 * a);
            double x2 = (- b - sqrt(d)) / (2 * a);
            vt.push_back(x1), vt.push_back(x2);
        } else if(d == 0) {
            double x1 = (- b) / (2 * a);
            vt.push_back(x1);
        }
    }
}

main() {
    freopen("EQUA.inp", "r", stdin);
    freopen("EQUA.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            vs = 1;
        solve(a, b, c);
    }
    if(vs == 1){
        cout << -1;
        return 0;
    }
    sort(vt.begin(), vt.end());
    vt.push_back(double(INT_MAX));
    for(int i = 0; i < vt.size() - 1; i++) {
        if(vt[i] != vt[i + 1])
            cnt++;
    }
    cout << cnt;
}
