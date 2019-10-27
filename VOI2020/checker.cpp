///Checker 2.0
///Shorten code, Easy to understand, Decrease execution time
#include <bits/stdc++.h>
#define maxn 200005
#define CHECKER "task name"
#define ll long long
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)
using namespace std;

///Initialize variables of submission, solution code
int n, a[maxn], t, nott;
int ans = 0, dem[1000005] = {0 };
bool answer;

///Initialize variables of judging code
clock_t start, finish, s, f, sss, fff;
double run, judge, an, mpoints, point, mtime, ann;
int judge1[100000] = {0}, judge2[100000] = {0}, cnt1 = 0, cnt2 = 0;

///Submission without initialize global variables, includes
void submission() {
    fi(CHECKER".inp");
    fo(CHECKER".out");

}

///Solution without initialize global variables, includes
void solution() {
    fi(CHECKER".inp");
    fo(CHECKER".ans");

}


/** Judge **/
///Read output
void input1() {
    fi(CHECKER".out");

}

///Read answer
void input2() {
    fi(CHECKER".ans");

}

///Check answer
void checker(int test) {
    cnt1 = 0, cnt2 = 0;
    input1(), input2();
    ofstream fileStream;
    fileStream.open("logs.txt",ios::out|ios::app);
    fileStream << "Test " << test << "\n";
    ///Generate logs

    fileStream.close();
}

/** End of judge part **/

///Generate random tests
void make_test() {
    srand(time(NULL));

}

void make_example() {
    fo(CHECKER".inp");

}

void make_testmax() {
    fo(CHECKER".inp");

}

///End of generate random tests

int test;
void setup() {
    cout << "NUMBER OF TEST: ";
    cin >> test;
    cout << "Maximum points: ";
    cin >> mpoints;
    cout << "Gioi han thoi gian";
    cin >> mtime;
}

void info() {
    sss = clock();
    ofstream fileStream;
    fileStream.open("logs.txt",ios::trunc);
    fileStream.close();
    make_example();
    for(int i = 1; i <= test; i++) {
        start = clock();
        submission();
        finish = clock();
        solution();
        checker(i);
        ofstream fileStream;
        fileStream.open("logs.txt",ios::out|ios::app);
        run = (double)(finish - start) / CLOCKS_PER_SEC;
        fileStream << "\nThoi gian code nop thuc hien chuong trinh: " << run << "\n";
        if(answer == true && run <= double(mtime)) {
            point += mpoints / double(test);
            fileStream << "Point: " << mpoints / double(test) << "\n\n";
        } else {
            if(run > 1)
                fileStream << "Time limit exceed\n";
            fileStream << "Point: 0" << "\n\n";
        }
        fileStream.close();
        make_test();
        if(i == test - 1)
            make_testmax();
    }
    ofstream fileStream1;
    fileStream1.open("logs.txt",ios::out|ios::app);
    fileStream1 << "\nTotal point: " << point << " / " << mpoints << "\n";
    fileStream1 << "Correct ratio: " << double(point) / mpoints * 100 << "%\n";
    fff = clock();
    ann = (double) (fff - sss) / CLOCKS_PER_SEC;
    fileStream1 << "Thoi gian cham toan bo " << test << " test: " << ann << " s";
    fileStream1.close();
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    setup();
    info();
}
