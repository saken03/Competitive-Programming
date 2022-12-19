/***
    AUTHOR:    shabylkhan
    CREATED:   21.07.2022 16:01:34

***/

#include<bits/stdc++.h>

using namespace std;

int dp[105][105];

bool match(char a, char b) {           
	if (a == '(' && b == ')') return 1;
	if (a == '[' && b == ']') return 1;
	if (a == '{' && b == '}') return 1;
	return 0;
}

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();

	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			dp[l][r] = 0;
			if (match(s[l], s[r])) {
				dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
			}
			dp[l][r] = max(dp[l][r], max(dp[l + 1][r], dp[l][max(r - 1, 0)]));
			for (int i = l + 1; i < r; i++) {
				if (match(s[l], s[i])) {
					dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
				}
			}
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