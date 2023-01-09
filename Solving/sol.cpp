#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;

void ckmax(ll& a, ll b) {
	a = max(a, b);
}

void solve() {
	int n, p, k;
	cin >> n >> p >> k;
	vector<pair<int, int>> aud(n);
	for (int i = 0; i < n; i++) {
		cin >> aud[i].f;
		aud[i].s = i;
	}
	sort(aud.rbegin(), aud.rend());
	vector<vector<int>> play(n, vector<int> (p));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> play[i][j];
		}
	}

	vector<vector<ll>> dp(n, vector<ll> (1 << p, -0x3f));
	dp[0][0] = aud[0].first;
	for(int i = 0; i < p; i++){
		dp[0][1 << i] = play[aud[0].second][i];
	}


	for (int i = 1; i < n; i++) {
		for (int m = 0; m < (1 << p); m++) {
			for (int k = 0; k < p; k++) {	
				if (m & (1 << k)) {
					ckmax(dp[i][m], dp[i - 1][m ^ (1 << k)] + play[aud[i].second][k]);
				}
			}
			ckmax(dp[i][m], dp[i - 1][m]);
			if (i - __builtin_popcount(m) < k) {
				ckmax(dp[i][m], dp[i - 1][m] + aud[i].f);
			}
		}
	}
	
	cout << dp[n - 1][(1 << p) - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}






