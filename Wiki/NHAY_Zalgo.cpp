#include <bits/stdc++.h>
using namespace std;

int t, n, z[4000005];
string a, b, s;

void zalgo(){
    int l = 0, r = 0;
    z[0] = 0;
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
        if(i > a.size() && z[i] == a.size())
            cout << i - a.size() - 1 << endl;
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n){
        cin >> a >> b;
        s = a + '#' + b;
        zalgo();
    }
}
