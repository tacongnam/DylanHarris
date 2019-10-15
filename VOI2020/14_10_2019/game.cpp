#include <bits/stdc++.h>
#define ft first
#define sd second
#define maxn 300005
using namespace std;
int t, n, d[maxn], dem[maxn];
pair<int, int> a[maxn];
main(){
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        memset(d, 0, sizeof(d));
        memset(dem, 0, sizeof(dem));
        scanf("%d", &n);
        for(int i = 1; i <= n * (n - 1) / 2; i++)
            scanf("%d%d", &a[i].ft, &a[i].sd);
        for(int i = 1; i < n * (n - 1) / 2; i++){
            if(a[i].ft == a[n*(n - 1)/2].ft || a[i].sd == a[n * (n - 1) / 2].ft)
                putchar('0'), putchar(' ');
            else
                putchar('1'), putchar(' ');
        }
        putchar('1'), putchar('\n');
    }
}
/*
1 4
1 4
2 1
1 3
4 2
2 3
3 4
*/
