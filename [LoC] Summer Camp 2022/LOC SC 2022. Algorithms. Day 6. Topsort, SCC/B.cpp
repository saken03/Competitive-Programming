/***
    AUTHOR:    shabylkhan
    CREATED:   25.07.2022 15:38:42

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[100500];
int pr[100500];
bool mark[100500], finished[100500];

void dfs(int v) {
	if (mark[v]) return;
	mark[v] = 1;
	for (int to : g[v]) {
		if (!mark[to]) {
			pr[to] = v;
			dfs(to);
		}
		else {
			if (!finished[to]) {
				cout << "YES\n";
				vector<int> path;
				while (v != to) {
					path.push_back(v);
					v = pr[v];
				}
				path.push_back(v);
				reverse(path.begin(), path.end());
				for (int i : path) cout << i << ' ';
				cout << '\n';
				exit(0);
			}
		}
	}
	finished[v] = 1;
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
	cout << "NO\n";
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