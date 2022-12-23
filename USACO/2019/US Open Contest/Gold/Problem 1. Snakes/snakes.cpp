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

const int INF = (int)1e10;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve() {        
	
	int n, k;
	cin >> n >> k;

	vector<int> groups(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> groups[i];
	}

	/*
		* dp[i][j] = the min sum of net sizes after
		* catching first i snakes with j resizings
	*/
	vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

	int largest_group = -1;
	int space_used = 0;
	for (int i = 1; i <= n; i++) {
		largest_group = max(largest_group, groups[i]);

		/*
		* base case: with zero resizings, Bessi must start off with
		* a net large enougth to catch the largest group of snakes
		*/
		dp[i][0] = largest_group * i;

		for (int j = 1; j <= k; j++) {
			dp[i][j] = INF;
			int net_size = groups[i];
			for (int c = i - 1; c >= 0; c--) {
		  	/*
		  	* consider the case where we switch
		  	* after collecting the first c groups
		  	*/
		  	dp[i][j] = min(dp[i][j], dp[c][j - 1] + net_size * (i - c));
		  	net_size = max(net_size, groups[c]);
			}
		}
		space_used += groups[i];
	}
	cout << dp[n][k] - space_used << '\n';
}

int main() {
	setIO("snakes");

	solve();

	return 0;
}   