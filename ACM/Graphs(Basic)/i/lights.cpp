#include<bits/stdc++.h>
using namespace std;
  
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> u(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		u[a]++;
		u[b]++;
	}
	for (int i = 0; i < n; i++) {
		cout << u[i] << ' ';
	}
	cout << '\n';
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("lights.in", "r", stdin);
	freopen("lights.out", "w", stdout);
	solve();
	return 0;
}