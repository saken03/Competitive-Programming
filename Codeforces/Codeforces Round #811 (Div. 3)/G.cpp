/***
    AUTHOR:    shabylkhan
    CREATED:   01.08.2022 22:33:49

***/

#include<bits/stdc++.h>

using namespace std;

int a[200500], b[200500], red[200500];
vector<int> g[200500], blue[200500];

void dfs(int v, int p, int r, vector<int> bl) {
	r += a[v];
	red[v] = r;
	bl.push_back(b[v]);
	blue[v] = bl;
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v, r, bl);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		red[i] = 0;
		blue[i].clear();
	}
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p >> a[i] >> b[i];
		g[p].push_back(i);	
	}
	vector<int> d = {};
	dfs(1, 0, 0, d);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < (int)blue[i].size(); j++) {
			blue[i][j] += blue[i][j - 1];
		}
	}
	for (int i = 2; i <= n; i++) {
	int l = 0, r = (blue[i].empty() ? 0 : (int)blue[i].size() - 1), ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (mid >= (int)blue[i].size()) break;
			if (blue[i][mid] <= red[i]) {
				ans = max(ans, mid);
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << ' '; 
	} 
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 