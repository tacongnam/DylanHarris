#include <bits/stdc++.h>
using namespace std;

int t, z[1000005];
string s;

void zalgo(){
    int l = 0, r = 0;
    z[0] = s.size();
    for(int i = 1; i < s.size(); i++){
        if(i > r){
            l = r = i;
            while(r < s.size() && s[r] == s[r-l])
                r++;
            z[i] = r - l;
            r--;
        }
        else{
            int k = i - l;
            if(z[k] < r - i + 1)
                z[i] = z[k];
            else{
                l = i;
                while(r < s.size() && s[r] == s[r-l])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        reverse(s.begin(), s.end());
        zalgo();
        int n, a;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a;
            cout << z[s.size() - a] << endl;
        }
    }
}
