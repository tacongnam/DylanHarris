#include<bits/stdc++.h>
using namespace std;
int res;
map < vector <int> , int> mapp;
void xuLy(int n, int X[], int num) {
    if(n == 0) {
        int temp, gg = X[1];
        vector <int> vt;
        for(temp = 1; temp < num; temp++) { // in ra từ X[1] tới X[i]
            gg = __gcd(gg, X[temp]);
            vt.push_back(X[temp]);
        }
        if(mapp[vt] == 1) {
            res++;
            return ;
        }
        else if(mapp[vt] == -1) {
            return ;
        }
        if(gg == 1) {
            res++, mapp[vt] = 1;
            return ;
        }
        else {
            mapp[vt] = -1;
            return ;
        }
    }
    for(int i = 1; i <= n; i++) {
        X[num] = i;
        xuLy(n - i, X, num + 1);
    }
}

int main() {
    int t;
    freopen("ANALYSE.inp", "r", stdin);
    freopen("ANALYSE.ans", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        int X[n + 1] = {0};  // mảng X có N + 1 phần tử
        int T[n + 1] = {0};
        xuLy(n, X, 1);  // mảng nghiệm tính từ i = 1
        cout << res << "\n";
        res = 0;
    }
    return 0;
}
