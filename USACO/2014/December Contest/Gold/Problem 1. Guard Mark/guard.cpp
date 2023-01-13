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

const int INF = (int)1e10;

int N, H;
int w[22], s[22], h[22];
pair<int, int> dp[1 << 22];

void solve() {        
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> h[i] >> w[i] >> s[i];
	}
	dp[0] = mp(0, INF);
	for (int msk = 1; msk < (1 << N); msk++) {
		dp[msk] = mp(0, -1);
		for (int i = 0; i < N; i++) {
			if (msk & (1 << i)) {
				dp[msk].f += h[i];
				dp[msk].s = max(dp[msk].s, min(dp[msk ^ (1 << i)].s - w[i], s[i]));
			}
		}
	}

	int ans = -1;
	for (int msk = 1; msk < (1 << N); msk++) {
		if (dp[msk].f >= H) {
			ans = max(ans, dp[msk].s);
		}
	}

	if (ans < 0) 
		cout << "Mark is too tall\n";
	else                 
		cout << ans << '\n';	
}

int main() {
	setIO("guard");

	solve();

	return 0;
}   
