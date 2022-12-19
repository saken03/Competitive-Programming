/***
    AUTHOR:    shabylkhan
    CREATED:   12.07.2022 22:34:57

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), dp(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0][0] = a[i];
	dp[0][1] = a[i] >> 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
	}
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