/***
    AUTHOR:    shabylkhan
    CREATED:   24.09.2022 18:44:04

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> g[MAXN];
int par[MAXN], lvl[MAXN];

void dfs(int v) {
	for (int to : g[v]) {
		if (to == v) {
			par[to] = v;
			lvl[to] = lvl[v] + 1;
			dfs(to);
		}
	}
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1);

	cout << par[5] << '\n';

  return;

	vector<int> X, Y;

	X.push_back(x);
	Y.push_back(y);

	while (lvl[x] > lvl[y]) {
	 	x = par[x];
		X.push_back(x);
	}

	while (lvl[x] < lvl[y]) {
		y = par[y];
		Y.push_back(y);
	}

	while (x != y && x != 0 && y != 0) {
		x = par[x];
		X.push_back(x);
		y = par[y];
		Y.push_back(y);
	}

	reverse(Y.begin(), Y.end());

	for (int i : X) cout << i << ' ';
	for (int i : Y) cout << i << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 