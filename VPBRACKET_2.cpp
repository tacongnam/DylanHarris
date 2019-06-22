    #include <bits/stdc++.h>
    #define maxn 100005
    using namespace std;
    int st[4*maxn+5],n,m,a[maxn];
    string s;
    void make_st(int node,int l,int r)
    {
        if(l==r)
        {
            st[node] = a[l];
            return;
        }
        make_st(node*2,l,(l+r)/2);
        make_st(node*2+1,(l+r)/2+1,r);
        st[node] = min(st[node*2],st[node*2+1]);
    }
    int get(int node,int l,int r,int u,int v)
    {
        if(r<u||v<l)
            return INT_MAX;
        if(u<=l && r<=v)
            return st[node];
        int a = get(node*2,l,(l+r)/2,u,v);
        int b = get(node*2+1,(l+r)/2+1,r,u,v);
        return min(a,b);
    }
    bool query(int l,int r)
    {
        //Check:
        if(a[r] != a[l-1]) //sum = 0
            return false;
        if(s[l] != '(' || s[r] != ')')
            return false;
        if(get(1,1,s.size()-1,l,r); != a[r])
            return false;
        return true;
    }
    int main()
    {
        cin>>s;
        s = ' ' + s;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='(')
                a[i] = a[i-1]+1;
            else
                a[i] = a[i-1]-1;
        }
        make_st(1,1,s.size()-1);
        cin>>m;
        while(m--)
        {
            int l,r;
            cin>>l>>r;
            if(query(l,r)==true)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
