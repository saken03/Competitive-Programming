#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	string a, b;
	cin >> a >> b;
	vector<vector<int>> dp(sz(a) + 1, vector<int> (sz(b) + 1, 10000));
	dp[0][0] = 0;
	for (int i = 0; i <= sz(a); i++) {
		for (int j = 0; j <= sz(b); j++) {
			if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			if (i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
		}
	}
	cout << dp[sz(a)][sz(b)];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
	
	return 0;
} 