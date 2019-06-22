    #include <bits/stdc++.h>
    #define maxn 10005
    #define maxst 30005
    #define int long long
    using namespace std;
    struct Node //Segment Tree cho toạ độ y (0 -> 30000)
    {
        int cnt; //Xem trên đoạn [l,r] mà Node quản lý có bao nhiêu HCN phủ lên
        int len; //Xem trên đoạn [l,r] mà Node quản lý độ dài phủ lên là bao nhiêu
    }st[4*maxst+5];
    struct inp
    {
        int x; //Toạ độ x
        int y1,y2; //Toạ độ y1,y2
        int type; //1 là mở, -1 là đóng
    }a[2*maxn+5];
    int cmp(inp a,inp b)
    {
        if(a.x == b.x)              //Nếu toạ độ x bằng nhau
            return a.type < b.type; //ưu tiên khoảng đóng trước
        else                        //Nếu không
            return a.x < b.x;       //sort theo toạ độ x
    }
    int n,res,k,m;
    void update(int node,int l,int r,int u,int v,int type)
    //Cập nhật toạ độ y từ [u,v] với type = 1 (mở), type = -1 (đóng)
    {
        if(r<u||v<l||u>v) //(l,r) nằm ngoài (u,v) hoặc u > v
            return;
        if(u<=l&&r<=v) //(l,r) nằm trong (u,v)
        {
            st[node].cnt += type;
            //Số HCN phủ lên cả đoạn [l,r] mà node quản lý
            if(type == 1) //Nếu khoảng này là khoảng mở thì toàn bộ [l,r]
                st[node].len = r-l+1; //được phủ, chiều dài phủ là r-l+1
            else if(st[node].cnt == 0)
            //Nếu khoảng này là khoảng đóng và số HCN phủ lên cả đoạn này bằng 0
            //thì chiều dài sẽ bằng tổng chiều dài của các Node con được phủ
            {
                if(l < r) //Nếu đây không phải nút lá
                    st[node].len = st[node*2].len + st[node*2+1].len;
                //Chiều dài phủ trên đoạn [l,r] bằng với chiều dài thành phần
                else
                    st[node].len = 0;
                //Node này không còn được phủ nên chiều dài bằng 0
            }
            //Nếu là khoảng đóng nhưng vẫn còn HCN phủ lên đoạn [l,r] -> không làm gì cả, vì đoạn [l,r] vẫn được phủ
            return;
        }
        update(node*2,l,(l+r)/2,u,v,type);
        update(node*2+1,(l+r)/2+1,r,u,v,type);
        if (st[node].cnt == 0 && l < r)
        //Nếu không có HCN nào phủ lên đoạn [l,r] và đây không phải lá
            st[node].len = st[node*2].len + st[node*2+1].len;
        //Chiều dài được phủ lên đoạn [l,r] bằng tổng chiều dài phủ lên đoạn [l,(l+r)/2] và [(l+r)/2+1,r]
    }
    main()
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            int x1,x2,y1,y2;
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            a[2*i] = {x1,y1+1,y2,1};      //Các hàng [y1+1,y2] bắt đầu được bao phủ bởi HCN này
            a[2*i+1] = {x2,y1+1,y2,-1};   //Các hàng [y1+1,y2] không được bao phủ bởi HCN này nữa
            k = max(k,y2);
        }
        sort(a+2,a+2*n+2,cmp);
        for(int i=2;i<=2*n+1;i++)
        {
            res += st[1].len * (a[i].x - a[i-1].x);
            //Phần được bao phủ giới hạn bởi hai đường thẳng đứng tại hoành độ a[i].x và a[i-1].x
            update(1,1,k,a[i].y1,a[i].y2,a[i].type);
            //Update đoạn [a[i].y1,a[i].y2] bắt đầu / kết thúc bao phủ
        }
        printf("%lld",res);
    }
