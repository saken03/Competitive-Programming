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

const int MAXN = 1005;

void solve() {        
	int N, M, C;
	cin >> N >> M >> C;

	vector<int> m(N);
	for (int i = 0; i < N; i++) cin >> m[i];
	
	vector<vector<int>> g(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; --a;--b;
		g[a].pb(b);
	}

	vector<vector<int>> dp(MAXN + 1, vector<int> (N, -1));
	dp[0][0] = 0;

	int ans = 0;
	for (int d = 0; d < MAXN; d++) {
		for (int i = 0; i < N; i++) {
			if (dp[d][i] != -1) {
				for (int j : g[i]) {
					dp[d + 1][j] = max(dp[d + 1][j], dp[d][i] + m[j]);
				}
			}
		}
		ans = max(ans, dp[d][0] - (C * d * d));
	}
	cout << ans << '\n';
}

int main() {
	setIO("time");

	solve();

	return 0;
}   
