#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

/// Digit DP template

long long dp[52][3][18][18][18];
vector <int> digit;

void getdigit(string x){
    digit.clear();
    for(int i = x.size() - 1; i >= 0; i--)
        digit.push_back(x[i] - '0');
}

long long getnum(int id, int tight, int n3, int n6, int n9){
    if(id == -1)
        return (n3 == n6 && n3 == n9 && n3 != 0);
    if(n3 > 16 || n6 > 16 || n9 > 16)
        return 0;
    if(dp[id][tight][n3][n6][n9] > -1 && tight == 0)
        return dp[id][tight][n3][n6][n9];
    int k = (tight == 0) ? 9 : digit[id];
    long long sum = 0;
    for(int i = 0; i <= k; i++){
        int newt = (digit[id] == i) ? tight : 0;
        sum = (sum + getnum(id - 1, newt, n3 + (i == 3), n6 + (i == 6), n9 + (i == 9))) % mod;
    }
    if(tight == 0)
        dp[id][tight][n3][n6][n9] = sum % mod;
    return sum % mod;
}

long long query(string l, string r){
    getdigit(l);
    long long a = getnum(digit.size() - 1, 1, 0, 0, 0);
    getdigit(r);
    long long b = getnum(digit.size() - 1, 1, 0, 0, 0);
    int n3 = 0, n6 = 0, n9 = 0;
    for(int i = 0; i < l.size(); i++){
        if(l[i] - '3' == 0)
            n3++;
        else if(l[i] - '6' == 0)
            n6++;
        else if(l[i] - '9' == 0)
            n9++;
    }
    return (b - a + (n3 == n6 && n3 == n9 && n3 > 0) + mod) % mod;
}

/// End of template

int t;
string l, r;

main(){
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        cin >> l >> r;
        printf("%lld\n", query(l, r));
    }
}
