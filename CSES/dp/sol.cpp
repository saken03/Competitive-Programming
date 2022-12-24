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

int n, a[105], cur, dp[MAXN];

void rec(int pos) {
	if (pos == n + 1) {
		dp[cur] = 1;
		return;
	} 
	cur += a[pos];
	rec(pos + 1);
	cur -= a[pos];
	rec(pos + 1);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<vector<bool>> dp(n + 1, vector<bool> (MAXN));
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][a[i]] = 1;
		for (int j = 0; j < MAXN; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - a[i] >= 0 && dp[i - 1][j - a[i]]) dp[i][j] = 1;
		}
	}
	
	vector<int> v;
	for (int i = 1; i < MAXN; i++) {
		if (dp[n][i]) v.pb(i);
	}
	cout << sz(v) << '\n';
	for (int i : v) cout << i << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}