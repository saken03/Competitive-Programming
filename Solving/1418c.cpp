#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int INF = (int)1e10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> dp(n + 1, vector<int> (INF));
	dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int who = 0; who < 2; who++) {
			for (int fight = 1; fight <= min(2, n - i); fight++) {
				int hard = a[i + 1] + (fight > 1 ? a[i + 1] : 0);
				if (dp[i][who] != INF) dp[i + fight][!who] = max(dp[i + fight][!who], dp[i][who] + hard);
			}
		}
	}
	cout << max(dp[n][0], dp[n][1]);
}

int main() {
int tt;
cin >> tt;
while (tt--) {
	solve();
}
	return 0;
}