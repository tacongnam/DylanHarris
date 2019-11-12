#include <bits/stdc++.h>
#define task "ANALYSE"
using namespace std;
// Tên chương trình
const string NAME = "ANALYSE";
// Số test kiểm tra
int NTEST, limit;
clock_t start, finish;
// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    cerr << "number of test: ";
    cin >> NTEST;
    cerr << "time limit: ";
    cin >> limit;
    freopen(task".log", "w", stdout);
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int t = rand() % 5 + 1;
        inp << t << "\n";
        while(t--)
            inp << rand() % 20 + 1 << "\n";
        // Code phần sinh test ở đây
        inp.close();



        // Nếu dùng Linux thì "./" + Tên chương trình
        cout << "Test " << iTest << ": \n\n";

        ///Run test and check time
        start = clock();
        system((NAME + ".exe").c_str());
        finish = clock();
        if(double(finish - start) / CLOCKS_PER_SEC > limit) {
            cout << "status: PARTICIPANT'S SOLUTION (PASS): TIME LIMIT EXCEED\n\n";
            return 2;
        }
        else
            cout << "time " << double(finish - start) / CLOCKS_PER_SEC << "; ";
        start = clock();
        system((NAME + "_trau.exe").c_str());
        finish = clock();
        if(double(finish - start) / CLOCKS_PER_SEC > limit && double(finish - start) / CLOCKS_PER_SEC <= 2 * limit) {
            cout << "status: JURY'S SOLUTION (FAILED) - TIME LIMIT EXCEED\n\n";
            cout << "Diagnose: time = " << double(finish - start) / CLOCKS_PER_SEC << "\n\n";
        }
        else if(double(finish - start) / CLOCKS_PER_SEC > 2 * limit){
            cout << "status: JURY'S SOLUTION (FAILED) - TIME LIMIT EXCEED\n\n";
            cout << "Diagnose: time = " << double(finish - start) / CLOCKS_PER_SEC << "\n\n";
            return -1;
        }

        ///Run test and check answer
        // Nếu dùng linux thì thay fc bằng diff
        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "status: PARTICIPANT'S SOLUTION (FAILED) - WRONG ANSWER!\n\n";
            return 1;
        }
        cout << "status: PARTICIPANT'S SOLUTION (PASS) - CORRECT ANSWER!\n\n";

        ///Run successfully
        cerr << iTest << " done!\n";
    }
    return 0;
}
