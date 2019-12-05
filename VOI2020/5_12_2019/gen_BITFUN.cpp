#include <bits/stdc++.h>
using namespace std;

main() {
    srand(time(NULL));
    freopen("BITFUN.inp", "w", stdout);
    int t = rand() % 10 + 1;
    cout << t << "\n";
//    /// sub123
//    while(t--) {
//        long long e = rand() % 100001;
//        cout << e << "\n";
//    }
    /// sub4
    vector <int> vt;
    for(int i = 0; i <= 28; i++)
        vt.push_back(i);
    while(t--) {
        random_shuffle(vt.begin(), vt.end());
        long long e = 0;
        for(int i = 1; i <= 30; i++) {
            if(i == vt[0] || i == vt[2] || i == vt[4])
                e += (1 << i);
        }
        e += (1 << 29);
        cout << e << "\n";
    }
}
