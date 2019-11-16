/// Im Gay. Don't tell anyone else ...						///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "ARITHDIG"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))
using namespace std;
vector<int> numA;
vector<int> numB;
string a,b;
int res;
bool checkA(int g)
{
    vector<int> c;
    c.push_back(numA[0]);
    for(int i=1;i<numA.size();i++)
    {
        if(numA[i]>(c[i-1]+g)%10)
            return false;
        else if(numA[i]<(c[i-1]+g)%10)
            return true;
        c.push_back((c[i-1]+g)%10);
    }
    return true;
}
bool checkB(int g)
{
    vector<int> c;
    c.push_back(numB[0]);
    for(int i=1;i<numB.size();i++)
    {
        if(numB[i]>(c[i-1]+g)%10)
            return true;
        if(numB[i]<(c[i-1]+g)%10)
            return false;
        c.push_back((c[i-1]+g)%10);
    }
    return true;
}
bool checkDB(int g)
{
    vector<int> c;
    c.push_back(numA[0]);
    for(int i=1;i<numA.size();i++)
        c.push_back((c[i-1]+g)%10);
    for(int i=0;i<numA.size();i++)
    {
        if(c[i]<numA[i])
            return false;
        if(c[i]>numA[i])
            break;
    }
    for(int i=0;i<numB.size();i++)
    {
        if(c[i]>numB[i])
            return false;
        if(c[i]<numB[i])
            break;
    }
    return true;
}
void laycan()
{
    if(numA.size()==1)
    {
        res++;
    }
    else
    {
        for(int i=0; i<=9; i++)
        {
            if(checkA(i))
                res++;
        }
    }
    if(numB.size()==1)
    {
        res++;
    }
    else
    {
        for(int i=0; i<=9; i++)
        {
            if(checkB(i))
                res++;
        }
    }
}
void tinh2()
{
    if(numB.size()==1)
    {
        res+=numB[0]-1;
    }
    else res+=(numB[0]-1)*10;
    if(numA.size()==1)
    {
        res+=9-numA[0];
    }
    else res+=(9-numA[0])*10;
}
void thdacbiet()
{
    if(numB[0]==numA[0])
    {
        for(int i=0; i<=9; i++)
            if(checkDB(i))
                res++;
    }
    else
        {
            laycan();
            res+=(numB[0]-numA[0]-1)*10;
        }
}
void tinh()
{
    int szA=numA.size();
    int szB=numB.size();
    res+=(szB-szA-1)*90;
}
void convert()
{
    numA.clear();
    numB.clear();
    for(int i=0; i<a.size(); i++)
    {
        numA.push_back(a[i]-'0');
    }
    for(int i=0; i<b.size(); i++)
    {
        numB.push_back(b[i]-'0');
    }
}
void nhap()
{
    cin>>a>>b;
    res=0;
    convert();
    if(numB.size()-numA.size()>=1)
    {
        laycan();
        tinh2();
        tinh();
        cout<<res<<'\n';
    }
    else if(numB.size()==numA.size()&&numA.size()==1)
    {
        cout<<numB[0]-numA[0]+1<<'\n';
    }
    else if(numB.size()==numA.size())
    {
        thdacbiet();
        cout<<res<<'\n';
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
        nhap();
}
