///....DH....///
#include <bits/stdc++.h>
using namespace std;

int nTest, timelim;
string num, task, checkcc, sol;

void make_test() {
    ofstream inp;
    inp.open((task + num + ".inp").c_str());
    /// gen test
    int a = rand() % 10000, b = rand() % 10000;
    inp << a << " " << b << "\n";
    inp.close();
}

void readfile(string start, string finish) {
    system(("copy " + start + " " + finish).c_str());
}

string add (string a) {
    string c = "";
    int nho = 0, tong;
    for(int i = a.size() - 1; i >= 0; i--) {
        if(i == a.size() - 1)
            tong = nho + (a[i] - '0' + 1);
        else
            tong = nho + (a[i] - '0');
        nho = tong / 10;
        tong = tong % 10;
        c.insert(0, 1, char(tong + 48));
    }
    if(nho > 0)
        c += char(nho + 48);
    return c;
}
main() {
    cout << "Copy file gen test, file solution (duoi .exe) tu bin\\Debug\\ vao thu muc bai lam!\n";
    cout << "Nhap ten file gen (khong ghi .exe)";
    cin >> checkcc;
    cout << "Nhap ten file solution: ";
    cin >> sol;
    cout << "Nhap so test: ";
    cin >> nTest;
    cout << "Header: ";
    cin >> task;
    cout << "From: ";
    cin >> num;
    for(int i = 1; i <= nTest; i++) {
        string sss = num;
        srand(time(NULL));
        system((checkcc + ".exe").c_str());
        readfile((task + ".inp").c_str(), ( task + num + ".inp").c_str());
        system(( sol + ".exe").c_str());
        readfile(( task + ".out").c_str(), ( task + num + ".out").c_str());
        num = add(num);
    }
}
