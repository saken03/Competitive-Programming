/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 13:50:17

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	while (q--) {
		int x;                                                                     
		cin >> x;
		int l = 0, r = n - 1;
		bool good = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] < x) {
				l = mid + 1;
			}
			else if (a[mid] > x) {
				r = mid - 1;
			}
			else {
				good = 1;
				break;
			}
		}
		cout << (good ? "YES" : "NO") << '\n';
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