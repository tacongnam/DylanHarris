#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long n, k;
vector <int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("PERMUTATIONLIST.inp", "r", stdin);
    freopen("PERMUTATIONLIST.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        res.push_back(i);
    long long cnt = 0;
    do{
        cnt++;
        if(cnt == k){
        for(int i = 0; i < n; i++)
            cout << res[i] << " ";
        return 0;
        }
    } while(next_permutation(res.begin(), res.end()));
    cout << "-1";
    return 0;
}
