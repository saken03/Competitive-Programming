#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<int> g[105];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> grass(n, -1);
	for (int i = 0; i < n; i++) {
		vector<bool> type(4);
		for (int to : g[i]) {
			if (grass[to] >= 0) type[grass[to]] = 1;
		}
		for (int j = 0; j < 4; j++) {
			if (!type[j]) {
				grass[i] = j;
				break;
			}
		}
		cout << grass[i] + 1;
	}
}

int main() {
	setIO("revegetate");

	solve();

	return 0;
}