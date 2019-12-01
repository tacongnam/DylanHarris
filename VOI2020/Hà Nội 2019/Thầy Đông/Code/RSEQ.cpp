///....DH....///
#include <bits/stdc++.h>
#define task                "RSEQ"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 200005;
                            const int MAXS = 500005;

struct setmem {
    int l, r;
    long long sum;
    int in;
};

struct compareSet {
    bool operator () (setmem const& a, setmem const& b) {
        if(a.l == b.l)
            return a.r < b.r;
        return a.l < b.l;
    }
};

int n, T, f, cnt;
long long smt[4 * MAXS], sum[maxn], s[maxn], res, a[maxn];

void update(int id, int l, int r, int pos, long long val) {
    if(pos < l || r < pos)
        return;
    if(l == r) {
        smt[id] = val;
        return ;
    }
    update(id * 2, l, (l+r)/2, pos, val);
    update(id * 2 + 1, (l+r)/2+1, r, pos, val);
    smt[id] = max(smt[id * 2], smt[id * 2 + 1]);
}

set < setmem ,  compareSet > st;

/// DPT: const. T. log(n. T)

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n >> T;
    For(i, 1, n, 1) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    sum[++cnt] = s[n];
    update(1, 1, MAXS, cnt, sum[cnt]);
    st.insert({1, n, s[n], cnt});
    res = smt[1];
    For(i, 1, T, 1) {
        cin >> f;
        if(st.size() > 0) {
        ///the element in which block?
            __typeof(st.begin()) it = st.lower_bound({f, n + 1, 0, 0});
            it--;
            setmem t = *it;
//            cout << t.l << " " << t.r << " " << t.sum << "\n";

        ///Erase that block, change its sum
            st.erase(it);
            sum[t.in] = -1;
            update(1, 1, MAXS, t.in, -1);
            res = smt[1];

        ///Add 2 new blocks, add theirs sum
            if(f != t.l) {
                sum[++cnt] = s[f - 1] - s[t.l - 1];
                update(1, 1, MAXS, cnt, sum[cnt]);
                st.insert({t.l, f - 1, sum[cnt], cnt});
                res = smt[1];
            }
            if(f != t.r) {
                sum[++cnt] = s[t.r] - s[f];
                update(1, 1, MAXS, cnt, sum[cnt]);
                st.insert({f + 1, t.r, sum[cnt], cnt});
                res = smt[1];
            }

            cout << res << "\n";
        }
        else
            cout << 0 << "\n";
    }
}
