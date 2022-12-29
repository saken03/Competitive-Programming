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
	int s, n;
	cin >> s >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<bool> dp(s + 1);
	dp[0] = 1;	
	for (int i = 1; i <= n; i++) {
		for (int j = s; j >= 0; j--) {
			if (j - a[i] >= 0 && dp[j - a[i]]) dp[j] = 1;
		}
	}

	for (int i = s; i >= 0; i--) {
		if (dp[i]) {
			cout << i << '\n';
			return;
		}
	}
}

int main() {
	setIO("knapsack");

	int tt = 1;
//	cin >> tt;
	while (tt--) { 
		solve();
	}

	return 0;
} 
