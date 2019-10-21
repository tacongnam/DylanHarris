///********???
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int cnt, n, k, s, l[maxn], r[maxn], status, d[maxn];

void updatet(int a[], int dem) {
    for(int i = 1; i <= dem; i++)
        if(a[i] != -1)
            d[a[i]]++;
}

void updateg(int a[], int dem) {
    for(int i = 1; i <= dem; i++)
        d[a[i]] = -1;
}

main() {
    freopen("FCOIN.inp", "r", stdin);
    freopen("FCOIN.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> s;
        for(int j = 1; j <= s; j++)
            cin >> l[j];
        for(int j = 1; j <= s; j++)
            cin >> r[j];
        cin >> status;
        if(status == 2)
            updatet(l, s), updateg(r, s), cnt++;
        else if(status == 1)
            updatet(r, s), updateg(l, s), cnt++;
        else
            updateg(l, s), updateg(r, s);
    }
    d[0] = cnt;
    int ans = 0;
    for(int i = n; i > 0; i--)
        if(d[i] == cnt) {
            if(ans != 0) {
                cout << 0;
                return 0;
            }
            ans = i;
        }
    cout << ans;
    return 0;
}

//Fake coin: 9, n = 10, k = 4
//Fake coin: 3, n = 4, k = 2
//Fake coin: 4, n = 5, k = 2
//Fake coin: 4, n = 5, k = 1
//Can't determine fake coin: n = 5, k = 2
//Can't determine fake coin: n = 8, k = 3
//Fake coin: 8, n = 8, k = 3
