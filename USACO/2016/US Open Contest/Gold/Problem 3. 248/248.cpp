/***
PROB: 
LANG: C++14
username: sakenseri1
***/
#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	vector<vector<int>> dp(n, vector<int> (n, -1));
	for (int i = 0; i < n; i++)
		dp[i][i] = a[i];
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) 
		for (int j = i + 1; j < n; j++) {
			if (dp[i + 1][j] == a[i]) 
				dp[i][j] = max(dp[i][j], a[i] + 1);	
			if (dp[i][j - 1] == a[j])
				dp[i][j] = max(dp[i][j], a[j] + 1);
			for (int k = i + 1; k < j; k++)
				if (dp[i][k] == dp[k + 1][j]) 
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
			ans = max(ans, dp[i][j]);
		}
	cout << ans << '\n';
}

int main() {
	setIO("248");

	solve();

	return 0;
}   
