/***
    AUTHOR:    shabylkhan
    CREATED:   16.09.2022 19:48:11

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5 * 1e4 + 5;

vector<int> g[MAXN];
int cost[MAXN], depth[MAXN], parent[MAXN][20], lg;

void dfs(int v) {
	for (int to : g[v]) {
		depth[to] = depth[v] + 1;
		parent[to][0] = v;
		dfs(to);
	}
}

int move(int x, int d) {
	for (int i = 0; i <= lg; i++) {
		if (d & (1 << i)) {
			x = parent[x][i];
		}
	}
	return x;
}

int lca(int u, int v) {
	if (depth[v] < depth[v]) {
		swap(u, v);
	}
	u = move(u, depth[u] - depth[v]);
	if (u == v) return v;
	for (int k = lg; k >= 0; k--) {
		int vp = parent[v][k];
		int up = parent[u][k];
		if (vp != up) {
			v = vp;
			u = up;
		}
	}
	return parent[u][0];
}

int ans(int x, int y) {
	int c = lca(x, y);

	int mn = (int) 1e7, v = x;
	while (v != c) {
		mn = min(mn, cost[v]);
	}
	v = y;
	while (v != c) {
		mn = min(mn, cost[v]);
	}

	return mn;
}

void solve() {
	int n;
	cin >> n;
	
	int nn = n;
	while (nn) {
		lg++;
		nn /= 2;
	}

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(i + 1);
		cost[i + 1] = y;
	}                 

	dfs(1);

	for (int k = 1; k <= lg; k++) {
		for (int i = 1; i <= n; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}

	int m;
	cin >> m;	

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << ans(x, y) << '\n';
	}
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