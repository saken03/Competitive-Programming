#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int INF = (int)1e10;

void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	vector<vector<int>> dp(505, vector<int> (505));
	for (int j = 0; j <= n; j++) {
		for (int i = 0; i < n - j; i++) {
			dp[i][i + j] = dp[i + 1][i + j] + 1;
			for (int k = i + 1; k <= i + j; k++) {
				if (s[i] == s[k]) {
					dp[i][i + j] = min(dp[i][i + j], dp[i + 1][k - 1] + dp[k + 1][i + j]);
				}
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}






