/***
PROB: 
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

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

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<ll> dp(n + 1);
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		int mx = a[i];
		for (int j = i; j >= max(1, i - k + 1); j--) {
			mx = max(mx, a[j]);
			dp[i] = max(dp[i], dp[j - 1] + mx * (i - j + 1));
		}
	}
	cout << dp[n] << '\n';
}

int main() {
	setIO("teamwork");

	solve();

	return 0;
}   
