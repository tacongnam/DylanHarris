///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define reset(m) memset(m,0,sizeof(m))
#define MOD 1000000007
#define int long long
#define maxn 100005
#define endl "\n"
using namespace std;
int T,numa,numb,res;
stack<int> st;
string a,b;
void sub1()
{
    for(int i=numa; i<=numb; ++i)
    {
        int u=i;
        while(u > 0)
        {
            st.push(u%10);
            u/=10;
        }
        int pre=-1,cosa=-1,ch=0;
        while(st.size())
        {
            int x=st.top();
            if(pre==-1)
            {
                pre=x;
            }
            else if(cosa==-1)
            {
                cosa=(x+10-pre) % 10;
                pre=x;
            }
            else if((pre+cosa) % 10 != x)
            {
                ch=1;
            }
            st.pop();
        }
        if(!ch)
            ++res;
    }
    cout<<res<<endl;
}
void sub2()
{
    int ch1=0,ch2=0;
    for(int i=1; i<=9; ++i)
    {
        if(i<a[0] -'0' || i > b[0] -'0')
            continue;
        for(int j=0; j<=9; ++j)
        {
            if(i==a[0]-'0')
                ch1=1;
            else
                ch1=2;
            if(i==b[0]-'0')
                ch2=1;
            int pre;
            int ch=0;
            for(int k=0; k<a.size(); ++k)
            {
                if(k==0)
                {
                    pre=i;
                }
                else
                {
                    int x=(pre + j) % 10;
                    if(ch1==1 && x < a[k]-'0')
                    {
                        ch=1;
                        break;
                    }
                    if(ch2==1 && x > b[k]-'0')
                    {
                        ch=1;
                        break;
                    }
                    if(ch1==1 && x > a[k]-'0')
                        ch1=2;
                    if(ch2==1 && x < b[k]-'0')
                        ch2=0;
                    pre=x;
                }
            }
            if(!ch)
                res++;
        }
    }
    cout<<res<<endl;
}
int cal(string x)
{
    int num=0;
    if(x.size()==1)
    {
        return (x[0]-'0');
    }
//    int cs1=0,cs0=0;
//    for(int i=0; i<x.size(); ++i)
//    {
//        if(x[i]=='0')
//            cs0++;
//    }
//    if(x[0]=='1' && cs0+1==x.size())
//    {
//        if(x.size()==2)
//            return 9;
//        else
//            return (x.size()-2)*90 + 9;
//    }
//    else
    {
        int cnt=x[0]-'1';
        num+=cnt*10 + (x.size()-2) *90 + 9;
        for(int j=0; j<=9; ++j)
        {
            int pre=x[0]-'0';
            int ch=0;
            for(int k=1; k<x.size(); ++k)
            {
                int y=(pre + j) % 10;
                if(y < x[k]-'0')
                {
                    num++;
                    break;
                }
                else if(y > x[k]-'0') break;
                pre=y;
                if(k==x.size()-1) num++;
            }
        }
        return num;
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("arithdig.inp", "r", stdin );
    freopen("arithdig.out", "w", stdout );
    cin >> T;
    while(T--)
    {
        cin >> a;
        cin >> b;
        numa=numb=0;
        res=0;
//        if(a.size()<=9)
//            for(int i=0; i<a.size(); ++i)
//            {
//                numa=numa*10+(a[i]-'0');
//            }
//        if(b.size()<=9)
//        {
//            for(int i=0; i<b.size(); ++i)
//                numb=numb*10+(b[i]-'0');
//        }
//        if(a.size()==b.size())
//            sub2();
//        else if(a.size()<=9 && b.size() <= 9 && numb-numa<=1e5)
//            sub1();
//          else
            {
                int ch=1;
                if(a.size() > 1)
                {
                    int cosa=(a[1]-a[0] + 10) % 10;
                    for(int i=2; i<a.size(); ++i)
                    {
                        if(((a[i-1] - '0') + cosa) % 10 != a[i]-'0')
                        {
                            ch=0;
                            break;
                        }
                    }
                }
                cout<<cal(b)-cal(a)+ch<<endl;
            }
    }
}
