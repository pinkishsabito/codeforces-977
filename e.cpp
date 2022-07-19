#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define x first
#define y second
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << '[' << #x << '=' << x << "]\n"

long long read() {
	bool Minus = false;
	long long result = 0;
	char ch = getchar();
	while (true) {
		if (ch == '-')  break;
		if (ch >= '0' && ch <= '9')  break;
		ch = getchar();
	}
	if (ch == '-')  Minus = true;
	else  result = ch - '0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9')  break;
		result = result * 10 + (ch - '0');
	}
	return Minus ? -result : result;
}

vector<vector<int>> g;
vector<bool> used;
bool good;

void dfs(int v) {
	used[v] = true;
	good &= (g[v].size() == 2);
	for (auto& to: g[v]) {
		if (used[to])  continue;
		dfs(to);
	}
}

int solve(const int mod = 1e9 + 9) {
	int n = read(), m = read();
	g.resize(n + 5);
	rep(i, 0, m) {
		int u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	used.resize(n + 5);
	int cnt = 0;
	rep(i, 1, n + 1) {
		if (!used[i]) {
			good = true;
			dfs(i);
			cnt += good;
			good = true;
		}
	}
	return cout << cnt << endl, 0;
}

int main(int argc, char **argv) {
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	#ifdef local
		freopen("stdin", "r", stdin);
		freopen("stdout", "w", stdout);
	#endif
	freopen("stderr", "w", stderr);
	int tests = 1; // read();
	while (tests--)  solve();
	cerr << endl << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	return 0;
}