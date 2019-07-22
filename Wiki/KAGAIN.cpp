#include <bits/stdc++.h>
using namespace std;
long long t;
main()
{
    cin >> t;
    while(t--)
    {
        stack <int> st;
        long long n, a[30005], L[30005], R[30005], res = 0, in;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        //Tìm kiếm L, R:
        a[0] = a[n+1] = -1;
        st.push(0);
        for(int i = 1; i <= n; i++)
        {
            while(a[st.top()] >= a[i])
                st.pop();
            L[i] = st.top() + 1;
            st.push(i);
        }
        while(st.empty())
            st.pop();
        st.push(n+1);
        for(int i = n; i >= 1; i--)
        {
            while(a[st.top()] >= a[i])
                st.pop();
            R[i] = st.top() - 1;
            st.push(i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(res < (R[i] - L[i] + 1) * a[i])
            {
                res = (R[i] - L[i] + 1) * a[i];
                in = i;
            }
        }
        printf("%lld %lld %lld\n", res, L[in], R[in]);
    }
}
