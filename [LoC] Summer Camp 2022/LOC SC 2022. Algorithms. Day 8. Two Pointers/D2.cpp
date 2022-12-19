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
	int r = 0, ans = 1e6;
	for (int l = 0; l < n; l++) {
//		long long seg = a[r] - (l ? a[l - 1] : 0);
		while (r < n && a[r] - (l ? a[l - 1] : 0) < s) {
			r++;
		}
		while (r > l && a[r] - (l ? a[l - 1] : 0) >= s) {
			ans = min(ans, r - l);
			cout << ans << ' ';
			r--;
		}
	}
	cout << '\n';
	cout << ans << '\n';
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