/***
    AUTHOR:    shabylkhan
    CREATED:   27.07.2022 15:47:02

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	long long s;
	cin >> n >> s;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += (i ? a[i - 1] : 0);
	}
	int ans = 1e6;
	for (int i = 0; i < n; i++) {
		int l = i, r = n - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] - (i ? a[i - 1] : 0) >= s) {
				ans = min(ans, mid - i);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	if (ans == 1e6) {
		cout << -1 << '\n';
		return;
	}
	cout << ans + 1 << '\n';
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