#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

void sub1() {
    int t = 1;
    cout << t << "\n";
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for(int i = 1; i <= n; i++) {
        int type = rand() % 10 + 1;
        int height = rand() % 10 + 1;
        cout << type << " " << height << "\n";
    }
}
main() {
    freopen("savetrees.inp", "w", stdout);
    sub1();
}
