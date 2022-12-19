/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 13:07:49

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 500;

int a[MAXN];
vector<int> t[MAXN * 4];

vector<int> merge(vector<int> a, vector<int> b) {
	if ((int) a.size() == 0) {
		return b;
	}
	if ((int) b.size() == 0) {
		return a;
	}
	
	int n = (int) a.size(), m = (int) b.size();
	vector<int> c(n + m);
	int i = 0, j = 0;
	
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			c[i + j] = a[i];
			i++;
		}
		else {
			c[i + j] = b[j];
			j++;
		}
	}

	while (i < n) {
		c[i + j] = a[i];
		i++;
	}
	while (j < m) {
		c[i + j] = b[j];
		j++;
	}

	return c;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].push_back(a[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = merge(t[v + v], t[v + v + 1]);
}

vector<int> query(int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl) return vector<int> (0);
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return merge(query(v + v, tl, tm, l, r), query(v + v + 1, tm + 1, tr, l, r));
}

pair<pair<long long, long long>, long long> dp[MAXN][2];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		memset(dp, 0, 100000);
		dp[l][0] = dp[l][1] = a[i];
		for (int i = l + 1; i <= r; i++) {
			dp[i][0].second = max(max(dp[i - 1].first.first, a[i]) - min(dp[i - 1].first.first, a[i]), dp[i - 1][1].first.second) + min(dp[i - 1].first.first, a[i]);
			dp[i][0].first.first = max(dp[i - 1].first.first, a[i]) - min(dp[i - 1].first.first, a[i]);
			dp[i][0].first.second = dp[i - 1][1];
		}
	}
}
                                                    
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 