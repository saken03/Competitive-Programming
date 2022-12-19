/***
    AUTHOR:    shabylkhan
    CREATED:   31.07.2022 23:07:48

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), sorted(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sorted[i] = a[i];
	}
	sort(sorted.begin(), sorted.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != sorted[i]) ans++;
	}
	cout << ans - 1 << '\n';
}

int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 