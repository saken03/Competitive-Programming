/***
PROB: 
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

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

int addone(int a, int b) {
	if (a == 0 && b == 2) return 1;
	if (a == 1 && b == 0) return 1;
	if (a == 2 && b == 1) return 1;
	return 0;
}

void solve() {        
	int n, k;
	cin >> n >> k;
	
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 2, vector<int> (3)));
	// h - 0
	// p - 1
	// s - 2
	// 0 wins 2, 1 wins 0, 2 wins 1
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		int x;
		if (c == 'H') x = 0;
		else if (c == 'P') x = 1;
		else x = 2;
		a[i] = x;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k + 1; j++) {
			int add = addone(0, a[i]);
			dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2])) + add;
			add = addone(1, a[i]);
			dp[i][j][1] = max(dp[i - 1][j][1], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2])) + add;
			add = addone(2, a[i]);
			dp[i][j][2] = max(dp[i - 1][j][2], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1])) + add;
			if (i == n) {
				ans = max(ans, max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2])));
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	setIO("hps");

	solve();

	return 0;
}   
