#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int f[maxn], w[maxn], n, a, b, d, ans = INT_MAX;

void sub1() { //Generate all permutations O(n!.n)
    vector <int> dd, vt;
    int t = 0;
    for(int i = 1; i <= n; i++)
        t += f[i];
    for(int t = max(a, d - t - 1); t <= min(b, d + t + 1); t++) {
        vt.clear();
        for(int i = 1; i <= n; i++)
            vt.push_back(i);
        do {
            int res = 0, timenow = t;
            for(int i = 0; i < n; i++) {
                timenow += f[vt[i]];
                res += abs(timenow - d) * w[vt[i]];
                if(res >= ans || timenow > b){
                    res = INT_MAX;
                    break;
                }
            }
            ans = min(ans, res);
        } while(next_permutation(vt.begin(), vt.end()));
    }
    cout << ans;
}
pair<int, int> pi[maxn];
bool isgreater(int x1, int x2, int y1, int y2){
    return (x1 * y2) > (x2 * y1);
}

bool cmp (pair<int, int> a, pair<int, int> b){
    return isgreater(a.first, a.second, b.first, b.second);
}

void sub3(){
    ans = 0;
    int timenow = a;
    for(int i = 1; i <= n; i++){
        timenow += pi[i].second;
        ans += abs(timenow - a) * pi[i].first;
    }
    cout << ans;
}

void sub4(){
    ans = 0;
    int timenow = b;
    for(int i = 1; i <= n; i++){
        ans += abs(timenow - b) * pi[i].first;
        timenow -= pi[i].second;
    }
    cout << ans;
}

void dq(int id, int kq, int boundl, int boundr){
    if(id == n){
        ans = min(ans, kq);
        return;
    }
    if(boundl - pi[id + 1].second >= a && kq + abs(boundl - d) * pi[id + 1].first < ans)
        dq(id + 1, kq + abs(boundl - d) * pi[id + 1].first, boundl - pi[id + 1].second, boundr);
    if(boundr + pi[id + 1].second <= b && kq + abs(boundr + pi[id + 1].second - d) * pi[id + 1].first < ans)
        dq(id + 1, kq + abs(boundr + pi[id + 1].second - d) * pi[id + 1].first, boundl, boundr + pi[id + 1].second);
}

void sub256(){
    for(int i = max(a, d - 100); i <= min(b, d + 100); i++)
        dq(0, 0, i, i);
    cout << ans;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("DBG.inp", "r", stdin);
    freopen("DBG.out", "w", stdout);
    cin >> n >> a >> b >> d;
    for(int i = 1; i <= n; i++)
        cin >> f[i] >> w[i];
    if(n <= 3){
        sub1();
        return 0;
    }
    for(int i = 1; i <= n; i++)
        pi[i] = make_pair(w[i], f[i]);
    sort(pi + 1, pi + n + 1, cmp);
    if(a == d)
        sub3();
    else if(b == d)
        sub4();
    else
        sub256();
}
