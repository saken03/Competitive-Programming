/***
    AUTHOR:    shabylkhan
    CREATED:   20.07.2022 15:45:16

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[100500];
int depth[100500], lg, parent[100500][20];

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
	if (depth[u] < depth[v]) {
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

int min_cost(int a, int b) {
	int c = lca(a, b);
	return (depth[c] - depth[a]) + (depth[c] - depth[b]);
}

void solve() {                        
	int n, m;
	cin >> n;

	int nn = n;
	while (nn) {
		lg++;
		nn /= 2;
	}   

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	dfs(0);
	
	for (int k = 1; k <= lg; k++) {
		for (int i = 1; i <= n; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << min_cost(a, b) << '\n';
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