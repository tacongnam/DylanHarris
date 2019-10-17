#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long base = 29;
const long long maxn = 2005;

long long hx[6][maxn], hn[6][maxn], po[maxn], n, maxlen;
string s[6];
vector <long long> d[6][maxn];

long long gethash(long long l, long long r, long long no, long long type){
    if(type == 1) //Xuoi
        return (hx[no][r] - hx[no][l - 1] * po[r - l] % mod + 200 * mod) % mod;
    else
        return (hn[no][l] - hn[no][r + 1] * po[r - l] % mod + 200 * mod) % mod;
}

void add(long long k){
    for(long long i = 0; i < s[k].size() / 2; i++)
        for(long long j = i; j < i + s[k].size() / 2; j++){
            long long len = j - i + 1;
            maxlen = max(maxlen, len);
            d[k][len].push_back(gethash(i, j, k, 1));
            d[k][len].push_back(gethash(i, j, k, 2));
        }
}

void solve(){
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j <= maxlen; j++)
            sort(d[i][j].begin(), d[i][j].end());
    for(long long j = maxlen; j >= 1; j--){
        for(long long l = 0; l < d[1][j].size(); l++){
            for(long long k = 2; k <= n; k++){
                long long h = lower_bound(d[k][j].begin(), d[k][j].end(), d[1][j][l]) - d[k][j].begin();
                if(h == d[k][j].size() || d[k][j][h] != d[1][j][l])
                    goto LM;
            }
            cout << j << endl;
            return;
            LM:;
        }
    }
}

void make_hash(long long no){
    hx[no][-1] = 0;
    for(long long i = 0; i < s[no].size(); i++)
        hx[no][i] = ((hx[no][i - 1] * base) % mod + (s[no][i] - 'a' + 1)) % mod;
    hn[no][s[no].size()] = 0;
    for(long long i = s[no].size() - 1; i >= 0; i--)
        hn[no][i] = ((hn[no][i + 1] * base) % mod + (s[no][i] - 'a' + 1)) % mod;
}

void make_po(){
    po[-1] = 1;
    for(long long i = 0; i <= maxlen + 2; i++)
        po[i] = po[i - 1] * base % mod;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("STR5.inp", "r", stdin);
    //freopen("STR5.out", "w", stdout);
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> s[i];
        s[i] = s[i] + s[i];
        maxlen = max(maxlen, (long long)(s[i].size()));
        make_hash(i);
    }
    make_po();
    maxlen = -1;
    for(long long i = 1; i <= n; i++)
        add(i);
    solve();
}
