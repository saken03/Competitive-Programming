#include<bits/stdc++.h>
using namespace std;
  
int g[105][105];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	bool good = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (!g[i][j]) good = 0;
		}
	}
	cout << (good ? "YES" : "NO") << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("complete.in", "r", stdin);
	freopen("complete.out", "w", stdout);
	solve();
	return 0;
}