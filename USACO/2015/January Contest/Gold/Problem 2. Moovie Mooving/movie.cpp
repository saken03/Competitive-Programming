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

const int MAXN = 22;
const int MAXC = 1010;

int N, L;

int D[MAXN];
int S[MAXN][MAXC];
int C[MAXN];

int dp[1 << MAXN];

int find(int val, int *ar, int len) {
  // bin search for greatest x s.t. ar[x] <= val
	int l = 0, r = len - 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ar[mid] <= val) {
			l = mid + 1;
			ans = mid;
		}
		else 
			r = mid - 1;
	}
	return ans;
}

void solve() {        
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> D[i] >> C[i];
		for (int j = 0; j < C[i]; j++) {
			cin >> S[i][j];
		}
	}

	for (int msk = 1; msk < (1 << N); msk++) {
		dp[msk] = -1;
	}

	int ans = -1;
	for (int msk = 0; msk < (1 << N); msk++) {
		int cur = dp[msk];
		if (cur == -1) continue;

		if (cur >= L) {
			int cnt = __builtin_popcount(msk);
			if (ans == -1 || cnt < ans) ans = cnt;
		}

		for (int i = 0; i < N; i++) {
			if (msk & (1 << i)) continue;
			int nmsk = msk | (1 << i);
			int idx = find(cur, S[i], C[i]);
			if (idx == -1) continue;

			int t = S[i][idx] + D[i];
			if (t > dp[nmsk]) dp[nmsk] = t;
		}
	}

	cout << ans << '\n';
}

int main() {
	setIO("movie");

	solve();

	return 0;
}   
