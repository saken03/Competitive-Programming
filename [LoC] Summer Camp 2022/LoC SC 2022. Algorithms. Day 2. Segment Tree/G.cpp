/***
    AUTHOR:    shabylkhan
    CREATED:   15.09.2022 13:31:19

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int a[MAXN], t[MAXN * 4];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = max(t[v + v], t[v + v + 1]);
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		t[v] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) 
		update(v + v, tl, tm, pos, val);
	else
		update(v + v + 1, tm + 1, tr, pos, val);

	t[v] = max(t[v + v], t[v + v + 1]);
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl) return -1e9;
	if (l <= tl && tr <= r) return t[v];
	
	int tm = (tl + tr) >> 1;
	return max(query(v + v, tl, tm, l, r), 
		query(v + v + 1, tm + 1, tr, l, r));
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	build(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		
		if (t == 1) {
			int pos, v;
			cin >> pos >> v;
			update(1, 0, n - 1, pos, v);
		}
		else {
			int x, j;
			cin >> x >> j;
			int l = j, r = n - 1, ans = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (query(1, 0, n - 1, l, mid) < x) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
					ans = min(ans, mid);
				}
			}
			if (ans == n) {
				cout << -1 << '\n';
				continue;
			}
			cout << ans << '\n';
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