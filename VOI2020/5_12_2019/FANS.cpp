///....DH....///
#include <bits/stdc++.h>
#define task "FANS"
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define pf push_front
#define reset(a, x) memset(a, x, sizeof(a))
#define For(i, s, n, m) for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m) for(int i = s; i >= n; i -= m)
using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

const int maxn = 20005;
int n, t, m, dp[maxn][2][7][7][7];
string s, dpp[205][2][7][7][7];

int mod(int a, int b) {
    return (a + b) % m;
}

string add (string a, string b) {
    int n1 = a.size(), n2 = b.size(), nho = 0, tong = 0;
    string c;
    if(n1 < n2)
        a.insert(0, n2 - n1, '0');
    else
        b.insert(0, n1 - n2, '0');
    for(int i = a.size() - 1; i >= 0; i--) {
        tong = nho + (a[i] - '0' + b[i] - '0');
        nho = tong / 10;
        tong = tong % 10;
        c.insert(0, 1, char(tong + '0'));
    }
    if(nho > 0)
        c.insert(0, 1, char(nho + '0'));
    return c;
}

int digit(int id, int minn, int maxx, int sum, int tight) {
    if((maxx - sum) > 2 || (sum - minn) > 2)
        return 0;
    if(id == 0)
        return 1;
    if(dp[id][tight][minn + 5][maxx + 5][sum + 5] > -1)
        return dp[id][tight][minn + 5][maxx + 5][sum + 5];
    if(tight == 1) {
        int a = digit(id - 1, min(minn, sum + 1), max(maxx, sum + 1), sum + 1, (s[n - id] == 'M') ? 1 : 0);
        int b = 0;
        if(s[n - id] == 'V')
            b = digit(id - 1, min(minn, sum - 1), max(maxx, sum - 1), sum - 1, 1);
        dp[id][tight][minn + 5][maxx + 5][sum + 5] = mod(a, b);
    }
    else {
        int a = digit(id - 1, min(minn, sum + 1), max(maxx, sum + 1), sum + 1, 0);
        int b = digit(id - 1, min(minn, sum - 1), max(maxx, sum - 1), sum - 1, 0);
        dp[id][tight][minn + 5][maxx + 5][sum + 5] = mod(a, b);
    }
    return dp[id][tight][minn + 5][maxx + 5][sum + 5];
}

string digit2(int id, int minn, int maxx, int sum, int tight) {
    if((maxx - sum) > 2 || (sum - minn) > 2)
        return "0";
    if(id == 0)
        return "1";
    if(dpp[id][tight][minn + 5][maxx + 5][sum + 5] != "\0")
        return dpp[id][tight][minn + 5][maxx + 5][sum + 5];
    if(tight == 1) {
        string a = digit2(id - 1, min(minn, sum + 1), max(maxx, sum + 1), sum + 1, (s[n - id] == 'M') ? 1 : 0);
        string b = "0";
        if(s[n - id] == 'V')
            b = digit2(id - 1, min(minn, sum - 1), max(maxx, sum - 1), sum - 1, 1);
        dpp[id][tight][minn + 5][maxx + 5][sum + 5] = add(a, b);
    }
    else {
        string a = digit2(id - 1, min(minn, sum + 1), max(maxx, sum + 1), sum + 1, 0);
        string b = digit2(id - 1, min(minn, sum - 1), max(maxx, sum - 1), sum - 1, 0);
        dpp[id][tight][minn + 5][maxx + 5][sum + 5] = add(a, b);
    }
    return dpp[id][tight][minn + 5][maxx + 5][sum + 5];
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> s;
        if(m > 0) {
            memset(dp, -1, sizeof(dp));
            cout << mod(digit(n, 0, 0, 0, 1), 0) << "\n";
        }
        else {
            memset(dpp, '\0', sizeof(dpp));
            cout << digit2(n, 0, 0, 0, 1) << "\n";
        }
    }
}
