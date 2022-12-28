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
	int n;
	cin >> n;
	vector<int> v(n, 1), dp(n + 1, INF);
	v[1] = 1;
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		int k = dp[i], p = 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
			if (dp[i] < k) {
				k = dp[i];
				p = 2;
			}
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
			if (dp[i] < k) {
				k = dp[i];
				p = 3;
			}
		}
		v[i] = p;
	}
	int p = n;
	vector<int> vec;
	while (p) {
		vec.pb(p);
		if (v[p] == 1) p--;
		else if (v[p] == 2) p /= 2;
		else p /= 3; 
	}

	reverse(vec.begin(), vec.end());
	cout << sz(vec) - 1 << '\n';
	for (int i : vec) cout << i << ' ';
}

int main() {
	setIO("calcul");

	int tt = 1;
//	cin >> tt;
	while (tt--) { 
		solve();
	}

	return 0;
} 
