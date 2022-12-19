#include<bits/stdc++.h>
using namespace std;
  
void solve() {
	int n, m;
	cin >> n >> m;    
	bool ok = 0;
	vector<vector<int>> u(n, vector<int> (n));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		u[a][b]++;
		if (u[a][b] > 1) ok = 1;
	}
	cout << (ok ? "YES" : "NO") << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("lights.in", "r", stdin);
	freopen("lights.out", "w", stdout);
	solve();
	return 0;
}