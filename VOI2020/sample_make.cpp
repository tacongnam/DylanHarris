//Dai Ca Di Hoc
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <windows.h>
#include <direct.h>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define maxn 1003
#define maxc 1000000003


using namespace std;

ofstream fi;
char Name_file[] = "";
char exe_file[100] = "";
char inp_file[100] = "";
char out_file[100] = "";
string folder = "Test00";

int random(int x)
{
    long long u = rand() % maxc;
    long long v = rand() % maxc;
    long long k = rand() % maxc;
    return ((u*v+k) % x + 1);
}


long long random(long long x)
{
    int u = random(1000000000);
    int v = random(1000000000);
    int k = random(1000000000);
    return ((1ll*u*v+k)%x)+1;
}

void make_test( int test)
{

}

void run_answer()
{
    system(exe_file);
}

void Rename_file(int test)
{
    folder[4] = test/10 + 48;
    folder[5] = test%10 + 48;
    mkdir(&folder[0]);
    string output_path = folder + "d:\kkk" + inp_file;
    CopyFile(inp_file, &output_path[0], false);
    output_path = folder + "d:\kkk" + out_file;
    CopyFile(out_file, &output_path[0], false);
}

void Make_file_name()
{
    strcpy(exe_file,Name_file);
    strcpy(inp_file,Name_file);
    strcpy(out_file,Name_file);

    strcat(exe_file,".exe");
    strcat(inp_file,".inp");
    strcat(out_file,".out");

}

int main()
{
    Make_file_name();
    FOR(test,0,19)
    {
        cout << test << endl;
        fi.open(inp_file);
        make_test(test);
        fi.close();
        run_answer();
        Rename_file(test);
    }
    DeleteFile(inp_file);
    DeleteFile(out_file);
    return 0;
}
