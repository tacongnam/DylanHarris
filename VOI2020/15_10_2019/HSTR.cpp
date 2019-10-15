#include <bits/stdc++.h>
#define maxn 3005
using namespace std;
string s1, s2;
int k, f[maxn][maxn], dem;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("HSTR.inp", "r", stdin);
    freopen("HSTR.out", "w", stdout);
    cin >> k >> s1 >> s2;
    s1 = ' ' + s1, s2 = ' ' + s2;
    for(int i = s1.size() - 1; i > 0; i--)
        for(int j = s2.size() - 1; j > 0; j--)
            if(abs(s2[j] - s1[i]) <= k)
                f[i][j] = f[i+1][j+1] + 1;
            else
                f[i][j] = 0;
    for(int i = 1; i < s1.size() - 2; i++)
    for(int j = i + 1; j < s1.size() - 1; j++){
        int sz1 = i, sz2 = j - i, sz3 = s1.size() - j - 1;
        if(f[1][1] >= sz1 && f[i + 1][sz1 + 1] >= sz2 && f[j + 1][sz1 + sz2 + 1] >= sz3)
            dem++;
        else if(f[1][1] >= sz1 && f[j + 1][sz1 + 1] >= sz3 && f[i + 1][sz1 + sz3 + 1] >= sz2)
            dem++;
        else if(f[i + 1][1] >= sz2 && f[1][sz2 + 1] >= sz1 && f[j + 1][sz1 + sz2 + 1] >= sz3)
            dem++;
        else if(f[i + 1][1] >= sz2 && f[j + 1][sz2 + 1] >= sz3 && f[1][sz2 + sz3 + 1] >= sz1)
            dem++;
        else if(f[j + 1][1] >= sz3 && f[1][sz3 + 1] >= sz1 && f[i + 1][sz1 + sz3 + 1] >= sz2)
            dem++;
        else if(f[j + 1][1] >= sz3 && f[i + 1][sz3 + 1] >= sz2 && f[1][sz2 + sz3 + 1] >= sz1)
            dem++;
    }
    cout << dem;
}
