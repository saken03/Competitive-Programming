#include<bits/stdc++.h>
using namespace std;
int main() {

int tt;
cin >> tt;
while (tt--) {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> dp(n + 2, vector<int> (2)); // dp[][]
	dp[0][1] = a[0];
	for (int i = 0; i < n; i++) {
		for (int t = 0; t < 2; t++) {
			if (t == 0) {
				dp[i + 1][t] = min(dp[i + 1][t], dp[i][t]);
				dp[i + 2][t] = min(dp[i + 1][t], dp[i][t]);
			}
			else {
				dp[i + 1][t] = min(dp[i + 1][t], dp[i][t] + a[i + 1]);
				dp[i + 2][t] = min(dp[i + 2][t], dp[i][t] + a[i + 2] + a[i + 1]);
			}
		}
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}
	return 0;
}