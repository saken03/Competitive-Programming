#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	int mx = 0;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		m[a - 1]++;
		m[b - 1]++;
	}
	for (int i = 0; i < n; i++) {
		mx = max(mx, m[i]);
	}
	cout << mx + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	solve();

	return 0;
}