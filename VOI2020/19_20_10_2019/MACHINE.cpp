#include <bits/stdc++.h>
#define ft first
#define sd second
using namespace std;

int n, res, F[3000005], maxx;
pair<int, int> a[1000005];

void read(int &P) {
    int thisChar = getchar();
    while (thisChar != ' ' && thisChar != '\n' && thisChar != EOF) {
        P = P * 10 + thisChar - '0';
        thisChar = getchar();
    }
}

void print(int P) {
    vector <char> vt;
    if(P == 0) {
        putchar('0');
        return;
    }
    while(P != 0) {
        int thisChar = P % 10;
        vt.push_back(thisChar + 48);
        P /= 10;
    }
    for(int i = vt.size() - 1; i >= 0; i--)
        putchar(vt[i]);
}

main() {
    freopen("MACHINE.inp", "r", stdin);
    freopen("MACHINE.out", "w", stdout);
    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i].ft), read(a[i].sd);
        F[a[i].sd] = (F[a[i].sd] > (a[i].sd - a[i].ft)) ? F[a[i].sd] : a[i].sd - a[i].ft;
        maxx = (a[i].ft + 1 - maxx > 0) ? (a[i].ft + 1) : maxx;
    }
    for(int i = 1; i <= maxx; i++)
        F[i] = (F[i] - F[i - 1] > 0) ? F[i] : F[i - 1];
    for(int i = 1; i <= n; i++)
        if(F[a[i].ft - 1] != 0) {
            int g = (a[i].sd - a[i].ft + F[a[i].ft - 1]);
            res = (res > g) ? res : g;
        }
    print(res);
}
