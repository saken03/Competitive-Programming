/***
PROB: 
LANG: C++14
username: sakenseri1
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

const int MAXN = 1005;

int n;
int pos[MAXN], dp[MAXN][MAXN][2];

void solve() {        
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pos[i];
	sort(pos, pos + n);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j) {                   
				dp[i][j][0] = abs(pos[i]) * n;
				dp[i][j][1] = abs(pos[j]) * n;
				continue;
			}
			int remaining = n - (j - i);
			if (i < n) {
				dp[i][j][0] = min(
					dp[i + 1][j][0] + abs(pos[i + 1] - pos[i]) * remaining,
				 	dp[i + 1][j][1] + abs(pos[j] - pos[i]) * remaining
				);
			}
			if (j > 0) {
				dp[i][j][1] = min(
					dp[i][j - 1][0] + abs(pos[i] - pos[j]) * remaining,
					dp[i][j - 1][1] + abs(pos[j - 1] - pos[j]) * remaining
				);
			}
		}
	}
	
	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
}

int main() {
	setIO("cowrun");

	solve();

	return 0;
}   
