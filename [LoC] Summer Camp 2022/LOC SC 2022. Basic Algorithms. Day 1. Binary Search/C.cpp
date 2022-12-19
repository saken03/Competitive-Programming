/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 14:20:06

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a.begin(), a.end());
	while (q--) {
		int x;
		cin >> x;
		int l = 0, r = n - 1, ans = 2e9;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] < x) {
				ans = min(ans, abs(a[mid] - x));
				l = mid + 1;
			}
			else if (a[mid] > x) {
				ans = min(ans, abs(a[mid] - x));
				r = mid - 1;
			}
			else {
				ans = 0;
				break;
			}
		}
		if (m[x - ans]) {
			cout << x - ans;
		}
		else cout << x + ans;
		cout << '\n';
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