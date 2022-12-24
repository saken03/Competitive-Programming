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

void solve() {        
	int t, a, b;
	cin >> t >> a >> b;
	vector<vector<int>> dp(2, vector<int> (t + 1));
	dp[0][0] = 1;
	for (int i = 0; i <= t; i++) {
		if (i - a >= 0) dp[0][i] |= dp[0][i - a];
		if (i - b >= 0) dp[0][i] |= dp[0][i - b];
		dp[1][i / 2] |= dp[0][i];
	}
	for (int i = 0; i <= t; i++) {
		if (i - a >= 0) dp[1][i] |= dp[1][i - a];
		if (i - b >= 0) dp[1][i] |= dp[1][i - b];
	}
	for (int i = t; i >= 0; i--) {
		if (dp[1][i]) {
			cout << i;
			return; 
		}
	}
}

int main() {
	setIO("feast");

	solve();

	return 0;
}   
