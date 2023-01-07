#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

typedef long long ll;

const ll MOD = (ll) 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> can(n, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> can[i][j];
		}
	}

	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int s = 1; s < (1 << n); s++) {
		int a = __builtin_popcount(s);
		for (int b = 0; b < n; b++) {
			if ((s & (1 << b)) == 1 && can[a][b]) {
				dp[s] += dp[s ^ (1 << b)];
				dp[s] %= MOD;
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}