/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 14:01:44

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	while (q--) {
		int x;
		cin >> x;
		int l = 0, r = n - 1, la = 1e6, ra = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid].first >= x) {
				if (a[mid].first == x) la = min(la, a[mid].second); 
				r = mid - 1;
			}
			else {
				l = mid + 1;
			} 
		}
		l = r;
		r = n - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid].first <= x) {
				if (a[mid].first == x) ra = max(ra, a[mid].second);
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		if (ra == -1) {
			cout << -1 << ' ' << -1 << '\n';
			continue;
		}
		cout << la << ' ' << ra << '\n';     
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