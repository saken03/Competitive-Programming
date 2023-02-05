#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int INF = (int)1e10;
const int MOD = (int)1e9 + 7;

void solve() {
	string s;
	cin >> s;
	
	int n = sz(s); // size of the string
	vector<vector<int>> dp(n, vector<int>(n)); // dp[l][r]

	for (int i = 0; i < n - 1; i++) 
		if (s[i] == s[i + 1]) 
			dp[i][i + 1] = 1;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			for (int k = i + 1; k < j; k++) {
				dp[i][j] += dp[i][k] + dp[k + 1][j];
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






