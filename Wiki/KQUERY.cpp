 #include <bits/stdc++.h>
 #define maxn 200005
 #define maxk 200005
 #define x first
 #define y second
 using namespace std;
 struct query
 {
     int f,s,k,in;
 };
 int cmp(query a,query b)
 {
     return a.k < b.k;
 }
 int cmpin(query a,query b)
 {
     return a.in < b.in;
 }
 int n,st[maxn],k,in = 1;
 pair<int,int> a[maxn];
 query b[maxk];
 void make_st(int node,int l,int r)
 {
     if(l == r)
     {
         st[node] = 1;
         return;
     }
     make_st(node*2,l,(l+r)/2);
     make_st(node*2+1,(l+r)/2+1,r);
     st[node] = st[node*2] + st[node*2+1];
 }
 void update(int node,int l,int r,int u) //Set b[u] = 0
 {
     if(u<l||r<u)
          return;
     if(l==r)
     {
         st[node] = 0;
         return;
     }
     update(node*2,l,(l+r)/2,u);
     update(node*2+1,(l+r)/2+1,r,u);
     st[node] = st[node*2] + st[node*2+1];
 } 
 int get(int node,int l,int r,int u,int v)
 {
     if(v<l||r<u)
          return 0;
     if(u<=l&&r<=v)
         return st[node];
     int a = get(node*2,l,(l+r)/2,u,v);
     int b = get(node*2+1,(l+r)/2+1,r,u,v);
     return a+b;
 }
 main()
 {
     scanf("%d",&n);
     for(int i=1; i<=n; i++)
         scanf("%d",&a[i].x),a[i].y=i;
     make_st(1,1,n);
     sort(a+1,a+1+n);
     scanf("%d",&k);
     for(int i=1; i<=k; i++)
     {
         scanf("%d%d%d",&b[i].f,&b[i].s,&b[i].k);
         b[i].in = i;
     }
     sort(b+1,b+1+k,cmp);
     for(int i=1; i<=k; i++)
     {
         while(a[in].x <= b[i].k && in <= n)
            update(1,1,n,a[in].y), in++;
         b[i].k = get(1,1,n,b[i].f,b[i].s);
     }
     sort(b+1,b+1+k,cmpin);
     for(int i=1;i<=k; i++)
         printf("%d \n",b[i].k);
 } 
