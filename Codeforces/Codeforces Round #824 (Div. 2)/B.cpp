/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 20:49:21

***/

#include<bits/stdc++.h>

using namespace std;

int mx = 0, mn = 1e8;

void div(int a) {
	mx = max(mx, a / 2 + (a & 1));
	mn = min(mn, a / 2);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		double x = mx, y = mn;
		while (x / y >= 2.0) {
			ans++;
			div(mx);
			x = max(1, mx), y = max(1, mn); 
		}
	}
	cout << ans << '\n';
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