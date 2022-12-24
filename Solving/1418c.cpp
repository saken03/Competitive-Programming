#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int INF = (int)1e10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<vector<ll>> dp(n + 2, vector<ll> (2, INF));
	dp[1][1] = a[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= min(n - i, 2); k++) {
				int bosses = a[i] + (k > 1 ? a[i + 1] : 0);
				dp[i + k][!j] = min(dp[i + k][!j], dp[i][j] + bosses * j);
			}
		} 
	}	
	cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
