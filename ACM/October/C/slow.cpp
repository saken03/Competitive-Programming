/***
    AUTHOR:    shabylkhan
    CREATED:   02.11.2022 19:05:27

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	long long sum = 0;
	bool sub2 = 1, sub5 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) sub2 = 0;
		if (a[i] < a[i - 1]) sub5 = 0;
		sum += a[i];
	}

	vector<long long> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] += pref[i - 1] + a[i];
	}

	if (n <= 1200) {
	long long mx = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			long long sum = pref[r] - pref[l - 1];
			int m = -1e4;
			for (int i = l; i <= r; i++) {
				m = max(m, a[i]);
			}   
			mx = max(mx, sum - m);
		}
	}
	cout << mx << '\n';
	return;
	}

	if (sub2) {
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
		}
		cout << pref[n] - mx << '\n';
		return;
	}

	if (sub5) {
		int l = 1, r = n - 1, id = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] <= a[n]) {
				r = mid - 1;
				id = mid;
			}
			else l = mid + 1;
		}
		cout << pref[n] - pref[id - 1] - a[n] << '\n';
		return;
	}
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