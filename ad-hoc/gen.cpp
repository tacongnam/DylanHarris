///...DH_judge...///
#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
const int NTEST = 100;

long long Rand(long long l, long long h)
{
    return rand() % (h - l + 1) + l;
}

bool edge[1005][1005];

int main() {
    srand(time(NULL));
    freopen("QOS.inp", "w", stdout);
    int n = 1000;
    int m = 100000;
    int t = Rand(1, n);
    int k = Rand(1, 10);
    cout << n << " " << m << " " << t << " " << k << "\n";
    vector < pair <int, int> > vt;
    vector <int> ed, ed1;
    for(int i = 1; i <= n; i++)
        ed.push_back(i);
    random_shuffle(ed.begin(), ed.end());
    for(int i = 0; i < n; i++) {
        if(ed[i] == 1) {
            int sw = Rand(0, 399);
            swap(ed[sw], ed[i]);
        }
        if(ed[i] == t) {
            int sw = Rand(0, 399);
            swap(ed[sw], ed[i]);
        }
    }
    ed1.push_back(0);
    for(int i = 1; i <= 400; i++) {
        ed1.push_back(ed[i - 1]);
        if(ed1[i] == 0)
            cerr << i << "AERROR!\n";
    }
    int cnt = 1;
    for(; cnt <= min(m, 79800); cnt++) {
        int a = Rand(1, 400);
        int b = Rand(1, 400);
        while(edge[ed1[a]][ed1[b]] == true) {
            a = Rand(1, 400);
            b = Rand(1, 400);
        }
        if(ed1[a] == 0 || ed1[b] == 0)
            cerr << "ERROR!";
        cout << ed1[a] << " " << ed1[b] << " " << Rand(1, 100) << "\n";
    }
    for(; cnt <= m; cnt++) {
        int a = Rand(0, n - 1);
        int b = Rand(0, n - 1);
        while(edge[ed[a]][ed[b]] == true) {
            a = Rand(0, n - 1);
            b = Rand(0, n - 1);
        }
        if(ed[a] == 0 || ed[b] == 0)
            cerr << "ERROR!";
        cout << ed[a] << " " << ed[b] << " " << Rand(1, 100) << "\n";
    }
    return 0;
}
