/***
    AUTHOR:    shabylkhan
    CREATED:   25.10.2022 19:33:20

***/

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
	int n, x;
	cin >> n >> x;        
	vector<int> a(n), dp(x + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}                        
	dp[0] = 1;
	for (int j = 1; j <= x; j++) {
	 for (int i = 0; i < n; i++) {
	 	if (j - a[i] >= 0) (dp[j] += dp[j - a[i]]) %= mod;
	 }
	}
	cout << dp[x] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 