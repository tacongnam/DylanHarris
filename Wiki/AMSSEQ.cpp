 #include <bits/stdc++.h>
 using namespace std;
 int main()
 {
     int F[10005],a,n,k,res=0;
     cin>>n>>k;
     for(int i=1;i<=n;i++)
     {
         cin>>a;
         F[i]=-1e8;
         for(int j=1;j<=k;j++)
              if(i-j>=0) F[i]=max(F[i],F[i-j]+a);
         res=max(res,F[i]);
     }
     cout<<res;
 }
