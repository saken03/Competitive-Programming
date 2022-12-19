/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 14:55:50

***/

#include<bits/stdc++.h>

using namespace std;

int n, k, t[105];

int time(int x) {
	int brn = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] > x) return 0;
		if (cur + t[i] <= x) {
			cur += t[i];
		}
		else {
			cur = t[i];
			brn++;
			if (brn > k) return 0;
		}
	}
	if (cur > x) return 0;
	brn++;
	if (brn > k) return 0;
	return brn;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	int l = 1, r = 1e9, ans = 1e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (time(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
//	cout << time(8);
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