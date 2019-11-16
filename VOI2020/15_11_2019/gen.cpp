//#include <bits/stdc++.h>
//using namespace std;
//const string NAME = "union";
//const string CODETRAU = "union_trau";
//const int NTEST = 100;
//
//long long Rand(long long l, long long h)
//{
//    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                (long long)rand() * (RAND_MAX + 1) +
//                rand()) % (h - l + 1);
//}
//
//
//int main() {
//    srand(time(NULL));
//    for(int iTest = 1; iTest <= NTEST; iTest++) {
//        ofstream inp((NAME + ".inp").c_str());
//        int n = rand() % 30 + 2;
//        inp << n << "\n";
//        set <int> st;
//        while(st.size() != n)
//            st.insert(rand() % 50 + 1);
//        for(auto it = st.begin(); it != st.end(); it++) {
//            inp << *it << " ";
//        }
//        inp.close();
//        system((NAME + ".exe").c_str());
//        system((CODETRAU + ".exe").c_str());
//        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
//            cout << "Test " << iTest << ": Wrong answer!\n";
//            return 0;
//        }
//        cout << "Test " << iTest << ": Correct answer!\n";
//    }
//    return 0;
//}
