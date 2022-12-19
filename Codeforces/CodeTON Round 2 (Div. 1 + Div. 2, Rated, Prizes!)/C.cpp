/***
    AUTHOR:    shabylkhan
    CREATED:   01.08.2022 12:39:49

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int fi = a[0];
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i] - 1;
	}
	a[n - 1] = n - a[n - 1] + fi - 2;
	sort(a.rbegin(), a.rend());
	int time = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - 2 * time > 2) {
			a[i] -= 2 * (time - 1);
			time++;
		}
		else if (a[i] - 2 * time > 0) {
			a[i] -= 2 * time;
			a[i]++;
			time++;
		}
		else {
			a[i] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	cout << n - ans << '\n';
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