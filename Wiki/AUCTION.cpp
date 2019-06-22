 #include <bits/stdc++.h>
 #define mod 1000000007
 using namespace std;
 long long n,a[1005],m;
 pair<long long,long long>res;
 int main()
 {
     res.first=1; res.second=0;
     a[-1]=0;
     cin>>n>>m;
     for(int i=0;i<m;i++)
     {
         cin>>a[i];
     }
     sort(a,a+m);
     for(int i=0;i<m;i++)
     {
             if(a[i]*min(m-i,n)>res.second)
             {
                 res.first=a[i];
                 res.second=a[i]*min(m-i,n);
             }
     }
     cout<<res.first<<" "<<res.second;
 }
