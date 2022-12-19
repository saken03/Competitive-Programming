/***
    AUTHOR:    shabylkhan
    CREATED:   21.07.2022 16:34:57

***/

#include<bits/stdc++.h>

using namespace std;

double dp[105][105];

void solve() {
	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) dp[i][i + 1] = (a[i] + a[i + 1]) / 2;
	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			double ans = dp[l][r];
			ans = max(ans, dp[l
		}
	}
	cout << dp[0][n - 1] << '\n';
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