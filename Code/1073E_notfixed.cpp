#include <bits/stdc++.h>
#define mod (998244353*1ll)
using namespace std;

/// Digit DP
long long k;
pair<long long, long long> dp[18][2][1056][2];
long long ten_pow[20];
vector <int> digit;

void getdigit(long long x){
    memset(dp, -1, sizeof(dp));
    digit.clear();
    do{
        digit.push_back(x % 10);
        x /= 10;
    } while(x > 0);
}

long long add(long long a, long long b){
    return (a + b + mod) % mod;
}

long long mul(long long a, long long b){
    return (a * b) % mod;
}

int countbit(long long x){
    int bit = 0;
    while(x > 0){
        bit += x & 1;
        x = x >> 1;
    }
    return bit;
}

pair<long long, long long> getsum(int id, int used, int tight, int last){
    if(countbit(used) > k)
        return {0, 0};
    if(id == -1)
        return {0, 1};
    if(dp[id][tight][used][last].first > -1 && tight == 0)
        return dp[id][tight][used][last];
    pair<long long, long long> res = {0, 0};
    int k1 = (tight == 0) ? 9 : digit[id];
    for(int i = 0; i <= k1; i++){
        int newt = tight | (i < digit[id]);
        int newl = last | (i > 0) | (id == 0);
        int newused = (newl == 1) ? (used | (1 << i)) : 0;
        /*
        int newt = (digit[id] == i) ? tight : 0;
        int newl = ((i > 0) || (last == 0 && id == 0)) ? 1 : last;
        int newused = (newl == 1) ? (used | (1 << i)) : used;
        */
        pair<long long, long long> curr = getsum(id - 1, newused, newt, newl);
        long long curway = curr.second;
        long long cursum = curr.first;
        res.first = add(res.first, add(mul(mul(i, ten_pow[id]), curway), cursum));
        res.second = add(curway, res.second);
        //res = res + i * ten_pow[id] * counter(id - 1, newt, newused, newl) + getsum(id - 1, newused, newt, newl);
    }
    if(tight == 0)
        dp[id][tight][used][last] = res;
    return res;
}

long long query(long long l, long long r){
    getdigit(l - 1);
    long long a = (getsum(digit.size() - 1, 0, 1, 0)).first;
    getdigit(r);
    long long b = (getsum(digit.size() - 1, 0, 1, 0)).first;
    return b - a;
}

long long l, r;
main(){
    ten_pow[0] = 1;
    for(int i = 1; i < 9; i ++) {
        ten_pow[i] = mul(ten_pow[i - 1], 10);
    }
    bit_count[0] = 0;
    for(int i = 1; i < (1 << 10); i ++) {
        bit_count[i] = bit_count[i & (i - 1)] + 1;
    }
    cin >> l >> r >> k;
    cout << query(l, r);
}
