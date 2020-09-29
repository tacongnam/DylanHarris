/** Begin template. Do not change this part **/
/** Author: GrintonDH **/

#include <bits/stdc++.h>

#define task				""
#define fi					freopen(task, "r", stdin);
#define fo 					freopen(task, "w", stdout);
#define FIO					ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, a, b)		for(auto (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)		for(auto (i) = (a); (i) >= (b); ++(i))

#define bit(a, i)			(((a) >> (i)) & 1)
#define mask(i)				(1LL << (i))
#define turn(a, i)			((a) ^ mask(i))

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define	rand()				rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug	cerr << "Debug status: \n"
#define debug(...) 	cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)	cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug	cerr << "\n"

/** End of template **/
/** Just enjoy my code **/


void testcase() {

}

main()
{
	start_debug;

	while() {
		testcase();
	}	

	end_debug;
}
