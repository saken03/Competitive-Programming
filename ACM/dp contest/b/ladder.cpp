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
	string s;
	cin >> n >> s;
	vector<int> dp(n, -1);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] != 'w') {
			vector<int> js = {1, 3, 5};
			for (int j : js) {
				if (i - j >= 0 && dp[i - j] != -1 && s[i - j] != 'w') {
					dp[i] = max(dp[i], dp[i - j]) + (s[i - j] == '"' ? 1 : 0);
				}
			}
		}
	}
	cout << dp[n - 1];
}

int main() {
	setIO("lepus");

	solve();

	return 0;
}   
