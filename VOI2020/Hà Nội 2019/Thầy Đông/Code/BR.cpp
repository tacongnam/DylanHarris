///....DH....///
#include <bits/stdc++.h>
#define task                "BR"
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
/** size of array **/       const int maxn = 205;

int cmp (string a, string b) {
    int n1 = a.size(), n2 = b.size();
    if(n1 < n2)
        a.insert(0, n2 - n1, '0');
    else
        b.insert(0, n1 - n2, '0');
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i])
            return -1;
        if(a[i] > b[i])
            return 1;
    }
    return -1;
}

string po[maxn], s[maxn];
int n, MAX;

string add(string a, string b) { /// Add 2 positive interger
    int n1 = a.size(), n2 = b.size(), nho = 0, tong = 0;
    string c = "";
    if(n1 < n2)
        a.insert(0, n2 - n1, '0');
    else
        b.insert(0, n1 - n2, '0');
    for(int i = a.size() - 1; i >= 0; i--) {
        tong = (nho + a[i] - 48) + (b[i] - 48);
        nho = tong / 10;
        tong = tong % 10;
        c.insert(0, 1, char(tong + 48));
    }
    if(nho > 0)
        c.insert(0, 1, char(nho + 48));
    while(c.size() > 0 && c[0] == '0') {
        c.erase(c.begin());
    }
    return c;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        Max(MAX, s[i].size() - 1);
    }
    po[0] = "1";
    for(int i = 1; i <= MAX; i++) {
        po[i] = po[i - 1];
        po[i] += '0';
    }
    string B = "0", R = "0";
    for(int i = 1; i <= n; i++) {
        for(int j = MAX; j >= 0; j--) {
            if(j < s[i].size()) {
                if(s[i][j] == 'B')
                    B = add(B, po[MAX - j]);
                else
                    R = add(R, po[MAX - j]);
            }
        }
    }
    if(cmp(B, R) == 1)
        cout << "B";
    else
        cout << "R";
}
