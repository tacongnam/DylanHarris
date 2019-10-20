#include <bits/stdc++.h>
#define maxn 2000005
#define pii pair<int, int>
using namespace std;

int n, l1, l2, res, maxx[maxn];
int a[maxn];
pii dp[maxn];
deque < pii > dq;
void check(int lim) {
    while(dq.size() > 0) {
        if(dq[0].second >= lim)
            return;
        else
            dq.pop_front();
    }
}

void read(int &P) {
    int thisChar = getchar();
    while (thisChar != ' ' && thisChar != EOF && thisChar != '\n') {
        P = P * 10 + thisChar - '0';
        thisChar = getchar();
    }
}

void print(int P){
    vector <char> vt;
    if(P == 0){
        putchar('0');
        return;
    }
    while(P != 0){
        int thisChar = P % 10;
        vt.push_back(thisChar + 48);
        P /= 10;
    }
    for(int i = vt.size() - 1; i >= 0; i--)
        putchar(vt[i]);
}

main() {
    freopen("GOLD.inp", "r", stdin);
    freopen("GOLD.out", "w", stdout);
    read(n);
    read(l1);
    read(l2);
    for(int i = 1; i <= n; i++)
        read(a[i]);
    for(int i = 1; i <= n; i++) {
        check(i - (l2 - l1 + 1));
        dp[i].second = i;
        if(i > l1)
            dp[i].first = a[i] + maxx[i];
        else
            dp[i].first = a[i];
        while(dq.size() > 0 && dq[dq.size() - 1].first < dp[i].first )
            dq.pop_back();
        dq.push_back(dp[i]);
        res = max(res, dp[i].first);
        maxx[i + l1] = dq[0].first;
    }
    print(res);
}
