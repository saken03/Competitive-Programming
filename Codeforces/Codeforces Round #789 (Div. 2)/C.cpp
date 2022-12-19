#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}

	for (int m = 3; m <= n - 2; m++) {
		// 1...m-1
		// m...n
		vector<int> l;
		for (int i = 1; i < m; i++) {
			l.push_back(a[i]);
		}
		vector<int> r;
		for (int i = m; i <= n; i++) {
			r.push_back(a[i]);
		}

		count(l, r);
	}
	cout << ans << '\n';
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