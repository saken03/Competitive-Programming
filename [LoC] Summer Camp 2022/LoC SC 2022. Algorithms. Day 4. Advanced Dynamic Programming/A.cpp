/***
    AUTHOR:    shabylkhan
    CREATED:   21.07.2022 15:44:18

***/

#include<bits/stdc++.h>

using namespace std;

int dp[105][105];
	
void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
		dp[i + 1][i] = 0;
	}

	for (int l = n - 1; l >= 0; l--) {
		for (int r = l + 1; r < n; r++) {
			if (s[l] == s[r]) {
				dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
			}
			dp[l][r] = max(dp[l][r], max(dp[l + 1][r], dp[l][r - 1]));
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