#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define sz(s) (int)(s.size ())
#define all(s) s.begin (), s.end ()
#define rall(s) s.rbegin (), s.rend ()
#define Unique(s) s.resize (unique (all (s)) - s.begin ())
#define fi first
#define se second
#define endl '\n'
#define Time clock () * 1.0 / CLOCKS_PER_SEC
#define sqr(x) ((x) * 1ll * (x))
#define lcm(a, b) ((a) / gcd (a, b) * (b))
#define rep(a, b, c) for (int a = b; a <= c; ++a)
#define per(a, b, c) for (int a = b; a >= c; --a)
#define _USE_MATH_DEFINES
#define int long long
using namespace std;
using namespace __gnu_pbds;
template<typename T>using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T1, typename T2>using ordered_map = tree<T1, T2, less<T1>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const double PI = (double)(acos (-1.0)), EPS = (double)(1e-7);
const int MOD = 1e9 + 7, PR = 15937, INF = 1 << 30, MXN = 2e2 + 17;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
template<typename T>inline bool updmin (T &a, T b) { return a > b ? a = b, 1 : 0; }
template<typename T>inline bool updmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template<typename T>inline T gcd (T a, T b) { while (a && b) a > b ? a %= b : b %= a; return a + b; }
int n, m, k, a[MXN];
unordered_map<ll, int>cnt;
int32_t main () {
	ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	//unsigned int FOR; asm ("rdtsc" : "=A" (FOR)); srand (FOR);
#ifdef _DeSeiSH_
	freopen ("Input.txt", "r", stdin);
	freopen ("OutputMain.txt", "w", stdout);
#else
	#define HaveFreOpen 0
	if (HaveFreOpen) {
		#define FileName ""
		freopen (FileName".in", "r", stdin);
		freopen (FileName".out", "w", stdout);
	}
#endif
	cin >> n;
	rep (i, 1, n)
		cin >> a[i], ++cnt[a[i]];
	rep (i, 1, n) {
		rep (j, 1, n)
			++cnt[a[j]];
		vector<int>res;
		int cur = a[i];
		while (1) {
			--cnt[cur];
			res.push_back (cur);
			if (cnt[cur * 2]) cur *= 2;
			else if (!(cur % 3) && cnt[cur / 3]) cur /= 3;
			else break;
		}
		if (sz (res) == n) {
			for (auto &to : res) cout << to << " ";
			return 0;	
		}
		res.clear ();
		rep (i, 1, n) cnt[a[i]] = 0;
	}
#ifdef _DeSeiSH_
	cerr << "\nMainCodeTime: " << Time << endl;
#endif
	return 0;
}