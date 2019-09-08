#include <bits/stdc++.h>
using namespace std;

/// Digit DP template

long long dp[12][100][3];
vector <long long> digit;

void getdigit(long long x){
    digit.clear();
    while(x != 0){
        digit.push_back(x % 10);
        x = x / 10;
    }
}

long long getsum(int id, long long sum, int tight){
    if(id == -1) //Nếu đã xét hết các chữ số
        return sum;
    if(dp[id][sum][tight] != -1 && tight == 0)
        return dp[id][sum][tight];
    long long res = 0;
    int k = (tight == 0) ? 9 : digit[id];
    for(int i = 0; i <= k; i++){
        int newt = (i == digit[id]) ? tight : 0;
        res += getsum(id - 1, sum + i, newt);
    }
    if(tight == 0)
        dp[id][sum][tight] = res;
    return res;
}

long long query(long long l, long long r){
    memset(dp, -1, sizeof(dp));
    getdigit(l - 1);
    long long a = getsum(digit.size() - 1, 0, 1);
    getdigit(r);
    long long b = getsum(digit.size() - 1, 0, 1);
    return b - a;
}

/// End of template
long long l, r;

main(){
    for(;;){
        scanf("%lld%lld", &l, &r);
        if(l == -1)
            return 0;
        printf("%lld\n", query(l, r));
    }
}
