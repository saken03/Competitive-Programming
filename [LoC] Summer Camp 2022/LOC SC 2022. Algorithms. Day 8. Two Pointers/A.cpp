/***
    AUTHOR:    shabylkhan
    CREATED:   27.07.2022 15:34:25

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c(n + m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			c[i + j] = a[i];
			i++;
		}
		else c[i + j] = b[j], j++;
	}
	while (i < n) c[i + j] = a[i], i++;
	while (j < m) c[i + j] = b[j], j++;

	for (int i : c) cout << i << ' ';
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