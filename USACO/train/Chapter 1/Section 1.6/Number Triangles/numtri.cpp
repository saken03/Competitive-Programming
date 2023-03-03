/***
PROB: numtri
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
 
const int N = 1005;

int dp[N][N];

void solve() {
	int r;
	cin >> r;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			int x;
			cin >> x;
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + x;	
		}
	}

	int mx = 0;
	for (int i = 1; i <= r; i++) 
		mx = max(mx, dp[r][i]);
	cout << mx << '\n';	
}

int main() {
	setIO("numtri");
	int tt = 1;
	// cin >> tt;
	while (tt--)
		solve();
	return 0;
}