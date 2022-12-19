/***
    AUTHOR:    shabylkhan
    CREATED:   25.07.2022 15:38:42

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[100500], t;
bool cycle, mark[100500], finished[100500];

void dfs(int v) {
	if (mark[v]) return;
	mark[v] = 1;
	for (int to : g[v]) {
		if (!mark[to]) {
			dfs(to);
		}
		else {
			if (!finished[to]) {
				cycle = 1;
			}
		}
	}
	finished[v] = 1;
	t.push_back(v);
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

	if (cycle) {
		cout << -1 << '\n';
		return;
	}

	reverse(t.begin(), t.end());
	for (int i : t) cout << i << ' ';
	cout << '\n';
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