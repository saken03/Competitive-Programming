#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 1e5 + 123;
const int INF = (int)1e12;

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
	vector<int> dp(n + 1);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j > 0) dp[i] += dp[i - j];
		}
	}
	cout << dp[n];
}

int main() {
	setIO("grig");

	int tt = 1;
//	cin >> tt;
	while (tt--) { 
		solve();
	}

	return 0;
} 
