/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 20:59:31

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), pref(n + 1);
	vector<long long> sum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = max(pref[i - 1], a[i]);
		sum[i] += sum[i - 1] + a[i];
	}
	while (q--) {
		int k;
		cin >> k;
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pref[mid] <= k) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}	
		if (ans == -1) {
			cout << 0 << ' ';
		}
		else cout << sum[ans] << ' ';
	}
	cout << '\n';
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
