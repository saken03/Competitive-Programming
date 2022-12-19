#include<bits/stdc++.h>
using namespace std;
  
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int> (n));
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
			for (int k = 0; k < n; k++) {
				if (i == k || j == k) continue;
				if (g[i][j] && g[j][k] && !g[i][k]) {
					good = 0;
					break;
				}
			}
		}
	}
	cout << (good ? "YES" : "NO") << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("transitive.in", "r", stdin);
	freopen("transitive.out", "w", stdout);
	solve();
	return 0;
}