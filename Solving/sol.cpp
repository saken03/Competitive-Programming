#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	// dp[msk] = {minimum number of rides, w is total weight of last ride
	// msk is persons we take overall      
	vector<pair<int, int>> dp(1 << n, mp(n + 1, 121212112));
	dp[0] = mp(1, 0);
	for (int i = 0; i < n; i++) 
		if (a[i] <= x) dp[1 << i] = mp(1, a[i]);
	for (int msk = 1; msk < (1 << n); msk++) {
		for (int i = 0; i < n; i++) {
		  if (msk & (1 << i)) {
		  	pair<int, int> prev = dp[msk ^ (1 << i)];
		  	int w = prev.s, r = prev.f;
		  	if (w + a[i] <= x) w += a[i];
		  	else r += 1, w = a[i];   
		  	dp[msk] = min(dp[msk], mp(r, w));
		  }
		  /*
			if ((msk & (1 << i)) == 0) {
				int nmsk = msk | (1 << i);
				if (dp[msk].s + a[i] <= x) 
					dp[nmsk] = min(dp[nmsk], mp(dp[msk].f, dp[msk].s + a[i]));
				else 
					dp[nmsk] = min(dp[nmsk], mp(dp[msk].f + 1, a[i]));
			}
			*/
		}
	}
	cout << dp[(1 << n) - 1].f << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}






