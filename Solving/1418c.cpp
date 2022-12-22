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
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> dp(n + 1, vector<int> (2, INF));
	dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int who = 0; who < 2; who++) {
			for (int fight = 1; fight <= min(2, n - i); fight++) {
				int hard = a[i] + (fight > 1 ? a[i + 1] : 0);
				dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + hard * who);
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
