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
	int n;
	cin >> n;
	vector<int> a(n), dp(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[1] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i + 1] = max(dp[i - 1], dp[i]) + a[i];
	}
	cout << dp[n] << '\n';
}

int main() {
	setIO("ladder");

	solve();

	return 0;
}   
