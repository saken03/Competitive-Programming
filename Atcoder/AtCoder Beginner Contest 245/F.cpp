#include<bits/stdc++.h>

using namespace std;

set<int> s;
bool used[200500];

void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to]) dfs(to);
		if (
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	cout << s.size() << '\n';

	return 0;
}