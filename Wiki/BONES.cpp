 #include <bits/stdc++.h>
 using namespace std;
 int MAX[1000000],Max=0,s1,s2,s3,res=0;
 int main()
 {
     cin>>s1>>s2>>s3;
     for(int i=1;i<=s1;i++)
         for(int j=1;j<=s2;j++)
             for(int f=1;f<=s3;f++)
     {
         MAX[i+j+f]++;
     }
     for(int i=3;i<=s1+s2+s3;i++)
     {
         if(MAX[i]>Max)
         {
             Max=MAX[i];
             res=i;
         }
     }
     cout<<res;
 }
