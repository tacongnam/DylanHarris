#include <bits/stdc++.h>
#define ft first
#define sd second
#define pii pair <int, int>
using namespace std;

pii w[5];
vector <pii> res;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("POUR.inp", "r", stdin);
    freopen("POUR.out", "w", stdout);
    cin >> w[1].ft >> w[2].ft >> w[3].ft;
    w[1].sd = 1, w[2].sd = 2, w[3].sd = 3;
    while(min(w[1].ft, min(w[2].ft, w[3].ft)) != 0){
        sort(w + 1, w + 4);
        int pour = w[2].ft / w[1].ft;
        int cnt = 0;
        for(int i = 0; i <= log2(pour); i++){
            int h = (pour >> i) & 1;
            if(h == 0){
                res.push_back({w[3].sd, w[1].sd});
                w[3].ft -= w[1].ft;
                w[1].ft *= 2;
            }
            else{
                res.push_back({w[2].sd, w[1].sd});
                w[2].ft -= w[1].ft;
                w[1].ft *= 2;
            }
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++)
        cout << res[i].ft << " " << res[i].sd << "\n";
}
