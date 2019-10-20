#include <bits/stdc++.h>
using namespace std;
int n, a[15];
vector <int> vt;

bool cmp (int a, int b){
    return a > b;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("LOTTO.inp", "r", stdin);
    freopen("LOTTO.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = (1 << n) - 1; i >= 63; i--){
        vt.clear();
        for(int j = n - 1; j >= 0; j--){
            if((i >> j) & 1 == 1)
                vt.push_back(a[j + 1]);
            if(vt.size() > 6)
                break;
        }
        if(vt.size() != 6)
            continue;
        for(int i = 0; i < vt.size(); i++)
            cout << vt[i] << " ";
        cout << endl;
    }
}
