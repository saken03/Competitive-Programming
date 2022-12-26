#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

const int MOD = (int)1e9 + 7;
const int MAXN = 100500;

void solve() {
	int n;
	cin >> n;
	
	vector<vector<char>> a(n + 1, vector<char> (n + 1));
	vector<vector<int>> dp(n + 1, vector<int> (n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	dp[1][1] = (a[1][1] == '.' ? 1 : 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '*') continue;
			if (a[i - 1][j] == '.')         
				dp[i][j] += dp[i - 1][j];
			if (a[i][j - 1] == '.') 
				dp[i][j] += dp[i][j - 1];
			dp[i][j] %= MOD;	
		}
	}
	cout << dp[n][n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}