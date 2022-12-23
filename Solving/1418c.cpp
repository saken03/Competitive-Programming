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

	vector<vector<int>> dp(n + 1, vector<int> (2, INF));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k < 3; k++) {
				int bosses = a[i] + (k > 1 ? 1 : a[i - 1]);
				dp[i][j] = min(dp[i][j], dp[i - k][!j] + bosses * !j);  
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
