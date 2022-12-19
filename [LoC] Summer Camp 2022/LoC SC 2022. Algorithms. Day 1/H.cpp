/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 15:10:29

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> g[55];
bool u[55];
int len, node;

void dfs(int v, int lvl, bool second = 0) {
	u[v] = 1;            
	if (len < lvl) {
		len = lvl;
		if (!second) node = v;
	}
	for (int to : g[v]) {
		if (u[to]) continue;
		dfs(to, lvl + 1);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'Y') g[i + 1].push_back(j + 1);
		}
	}
	int cnt = 0;     
	for (int i = 1; i <= n; i++) {
		if (!u[i]) {
			if (cnt) {
				cout << -1 << '\n';
				return;
			}
			dfs(i, 0);
			cnt = 1;
		}
	}
	dfs(node, 0, 1);
	cout << len * k << '\n';
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
