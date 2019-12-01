///....DH....///
#include <bits/stdc++.h>
#define task                "WBRACKET"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 200005;

long long n, k, F[125][125][3];
char x[125];

long long calc (int i, int c, bool ok) {
    if (i > n)
        return (ok == false || (c != n - c));
    if(F[i][c][ok] > -1)
        return F[i][c][ok];
    return F[i][c][ok] = calc (i + 1, c + 1, ok) + calc(i + 1, c, ok & ((i - c) <= c));
}

void truyvet(int i, int c, bool ok) {
    if(i > n)
        return ;
    if(k <= calc (i + 1, c + 1, ok))
        cout << "(",  truyvet(i + 1, c + 1, ok);
    else {
        k -= calc(i + 1, c + 1, ok);
        cout << ")";
        truyvet(i + 1, c, ok & ((i - c) <= c));
    }
}

bool check(int in) {
    int dem = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(((in >> i) & 1) == 0)
            dem++;
        else
            dem--;
        if(dem < 0)
            return false;
    }
    if(dem == 0)
        return true;
    else
        return false;
}

void print(int in) {
    cout << "Answer: ";
    for(int i = n - 1; i >= 0; i--) {
        if(((in >> i) & 1) == 0)
            cout << "(";
        else
            cout << ")";
    }
    cout << "\nOutput: ";
}

void getans(int kk) {
    for(int i = 0; i < (1 << n); i++) {
        if(check(i) == false)
            kk--;
        if(kk == 0) {
            print(i);
            break;
        }
    }
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    memset(F, -1, sizeof(F));
    cin >> n >> k;
    //getans(k);
    calc(1, 0, 1);
    truyvet(1, 0, 1);
}
