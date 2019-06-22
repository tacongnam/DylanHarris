 #include <bits/stdc++.h>
 #define maxn 1000005
 using namespace std;
 //Initialization struct
 struct Node
 {
     int ok,o,c; 
     make_Node(int okk,int open,int close)
     {
         ok = okk;
         o = open;
         c = close;
     }
 };
 //Merge 2 nodes:
 Node operator + (Node id1,Node id2)
  {
     Node res;
     int temp = min(id1.o,id2.c);
     res.ok = id1.ok + id2.ok + temp;
     res.o = id1.o + id2.o - temp;
     res.c = id1.c + id2.c - temp;
     return res;
 }
 Node st[4*maxn+5];
 int n,m;
 string s;
 //Initialization Segment Tree
 void make_st(int node,int l,int r)
 { 
     if(l==r)
     {
         if(s[l]=='(')
             st[node].make_Node(0,1,0);
         else
             st[node].make_Node(0,0,1);
         return;
     }
     make_st(node*2,l,(l+r)/2);
     make_st(node*2+1,(l+r)/2+1,r);
     st[node] = st[node*2] + st[node*2+1];
 }
 Node get(int node,int l,int r,int u,int v)
 {
     if(v<l||r<u)
     {
         Node a = {0,0,0};
         return a;
    }
      if(u<=l&&r<=v)
         return st[node];
     Node a = get(node*2,l,(l+r)/2,u,v);
     Node b = get(node*2+1,(l+r)/2+1,r,u,v);
     return a + b;
 }
 main()
 {
    cin>>s;
     s = ' ' + s;
     make_st(1,1,s.size()-1);
    cin>>m;
     while(m--)
     {
         int l,r;
         scanf("%d%d",&l,&r);
         Node res = get(1,1,s.size()-1,l,r);
         printf("%d\n",res.ok*2);
     }
 }
