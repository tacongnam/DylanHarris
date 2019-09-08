#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
string a,s;
ll hashA=0,hashS[1000005]={0},po[1000005]={0};
void solve()
{
    for(ll i=a.size()-1;i<s.size();i++)
    {
        ll f=(hashS[i]-hashS[i-a.size()]*po[a.size()-1]%mod+mod)%mod;
        if(f==hashA) cout<<i-a.size()+1<<endl;
    }
}
void setting()
{
    hashA=0;
    for(int i=0;i<a.size();i++)
    {
        hashA=((hashA*26)%mod+a[i]-'a'+1+mod)%mod;
    }
    hashS[-1]=0; po[-1]=1;
    for(int i=0;i<s.size();i++)
    {
        hashS[i]=((hashS[i-1]*26)%mod+s[i]-'a'+1+mod)%mod;
        po[i]=(po[i-1]*26)%mod;
    }
}
void nhap()
{
    ll l;
    while(cin>>l)
    {
        cin>>a>>s;
        setting();
        solve();
    }
}
int main()
{
    nhap();
}
