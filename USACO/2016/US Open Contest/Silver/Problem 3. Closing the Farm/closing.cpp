#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int n, m;
const int MAXN = 3000;

vector<vector<int>> g(MAXN);
vector<int> vis(MAXN), closed(MAXN);
int nodes;

void dfs(int node) {
	if (vis[node] || closed[node]) return;

	nodes++;
	vis[node] = 1;

	for (int to : g[node]) 
		if (!vis[to]) dfs(to);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0);

	cout << (nodes == n ? "YES" : "NO") << '\n';

	vector<int> ord(n);

	for (int i = 0; i < n; i++) 
		cin >> ord[i], ord[i]--;

	for (int i = 0; i < n - 1; i++) {
		nodes = 0;
		closed[ord[i]] = 1;
		fill(vis.begin(), vis.end(), 0);

		dfs(ord[n - 1]);
		cout << (nodes == n - i - 1 ? "YES" : "NO") << '\n';
	}

	return 0;
}