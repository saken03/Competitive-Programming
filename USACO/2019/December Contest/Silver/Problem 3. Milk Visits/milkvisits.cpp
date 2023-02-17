/***
PROB: 
LANG: C++14
username: sakenseri1
***/
#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MAXN = 1e5 + 10;

int n, m;
string type;
vector<int> g[MAXN];
bool found;

void dfs(int v, int p, int f, char mo, bool met) {
	met = (type[v] == mo);

	if (v == f)	{
		found = met;
		return;
	}

	for (const int to : g[v]) {
		if (to == p) continue;
		return dfs(to, v, f, mo, met);
	}
}

void solve() {
	cin >> n >> m >> type;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	while (m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		dfs(a, -1, b, c, 0);
		cout << found;
	}
}

int main() {
	setIO("milkvisits");

	solve();

	return 0;
}   
