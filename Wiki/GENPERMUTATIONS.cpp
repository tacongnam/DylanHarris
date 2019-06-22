    #include <bits/stdc++.h>
    #define FOR(a,b,c) for(ll i = a; i <= b; i += c)
    #define ll long long
    using namespace std;
    ll n,k,cnt;
    vector<ll> per;
    main()
    {
         cin>>n>>k;
         FOR(1,n,1)
             per.push_back(i);
         do
         {
             cout<<++cnt<<". ";
             FOR(0,per.size()-1,1)
                cout<<per[i]<<" ";
             cout<<"\n";
         }
         while(next_permutation(per.begin(),per.end()) && (k - cnt));
    }
