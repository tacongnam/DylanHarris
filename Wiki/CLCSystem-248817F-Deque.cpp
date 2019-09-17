#include<bits/stdc++.h>
#define float double
using namespace std;
int n,q;
float p;
struct Line
{
    double a,b;
} l[200005];
deque <Line> dq;
bool slope_cmp (Line x,Line y)
{
    return (x.a>y.a || x.a==y.a && x.b<y.b);
}
double intersection(Line x,Line y)
{
    return (y.b-x.b)/(x.a-y.a);
}
double Y(int index,double X)
{
    return dq[index].a*X+dq[index].b;
}
bool Check (Line Prev,Line Now,Line X)
{
    return (double)(X.b-Now.b)*(Prev.a-Now.a)<=(double)(Now.b-Prev.b)*(Now.a-X.a);
}
void Add (Line X)
{
    if(dq.size()>0 && X.a == (dq[dq.size()-1]).a)
        return;
    while (dq.size()>1 && Check(dq[dq.size()-2],dq[dq.size()-1],X)==1)
        dq.pop_back();
    dq.push_back(X);
}
double Get (double X)
{
    if (dq.size()==1)
        return Y(0,X);
    int l=0,r=dq.size()-1;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (Y(mid,X)>=Y(mid+1,X))
            l=mid+1;
        else
            r=mid;
    }
    return Y(l,X);
}
int main()
{
    //freopen("CHT.inp","r",stdin);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%lf%lf",&l[i].a,&l[i].b);
    sort (l+1,l+1+n,slope_cmp);
    for (int i=1; i<=n; i++)
        Add(l[i]);
    printf("%d\n",dq.size()-1);
    int cnt=0;
    if (dq.size()>1)
    {
        while (cnt<=dq.size()-2)
        {
            double giaodiem=intersection(dq[cnt],dq[cnt+1]);
            printf("%.8f ",giaodiem);
            cnt++;
        }
        printf("\n");
    }
    scanf("%d",&q);
    for (int i=1; i<=q; i++)
    {
        scanf("%lf",&p);
        printf("%.8f\n",Get(p));
    }
}
