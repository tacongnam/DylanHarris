///...DH_judge...///
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const string NAME = "REGION";
const string CODETRAU = "REGION_trau";
const int NTEST = 100;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int t[100][100];

int main() {
    srand(time(false));
    for(int iTest = 1; iTest <= NTEST; iTest++) {
        ofstream inp((NAME + "S.inp").c_str());
        memset(t, 0, sizeof(t));
        int n = rand() % 4 + 10;
        int m = rand() % (n * (n - 1) / 2) + 1;
        int k = rand() % (n * (n - 1) / 2 - m) + 1;
        inp << n << " " << m << " " << k << "\n";
        for(int i = 1; i <= m; i++){
            int u = rand() % n + 1;
            int v = rand() % n + 1;
            while(t[u][v] == 1 || u == v) {
                u = rand() % n + 1;
                v = rand() % n + 1;
                if(u == v) {
                    int x = rand() % u + 1;
                    u -= x;
                }
            }
            inp << u << " " << v << "\n";
            t[u][v] = 1;
        }
        inp.close();
        system((NAME + ".exe").c_str());
        system((CODETRAU + ".exe").c_str());
        if(system(("fc " + NAME + "S.out " + NAME + "S.ans").c_str()) != 0) {
            cout << "Test " << iTest << ": Wrong answer!\n";
            return 0;
        }
        cout << "Test " << iTest << ": Correct answer!\n";
    }
    return 0;
}
