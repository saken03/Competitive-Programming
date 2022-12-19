/***
    AUTHOR:    shabylkhan
    CREATED:   20.10.2022 21:02:52

***/

#include<bits/stdc++.h>

using namespace std;

int n;
int a[200500], b[200500];

void solve() {
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i], ans += a[i];
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		ans += b[i];
		mx = max(mx, b[i]);
	}
	cout << ans - mx << '\n';
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