/***
    AUTHOR:    shabylkhan
    CREATED:   15.09.2022 14:00:01

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int a[MAXN], t[2][MAXN * 4];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		if (tl & 1) {
			t[0][v] = a[tl];
			t[1][v] = -a[tl];
		}
		else {
			t[0][v] = -a[tl];
			t[1][v] = a[tl];
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[0][v] = t[0][v + v] + t[0][v + v + 1];
	t[1][v] = t[1][v + v] + t[1][v + v + 1];
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		if (tl & 1) {
			t[0][v] = val;
			t[1][v] = -val;
		}
		else {
			t[0][v] = -val;
			t[1][v] = val;
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		update(v + v, tl, tm, pos, val);
	}
	else {
		update(v + v + 1, tm + 1, tr, pos, val);
	}
	t[0][v] = t[0][v + v] + t[0][v + v + 1];
	t[1][v] = t[1][v + v] + t[1][v + v + 1];
}

int getsum(int tp, int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl) return 0;
	if (l <= tl && tr <= r) return t[tp][v];
	int tm = (tl + tr) >> 1;
	return getsum(tp, v + v, tl, tm, l, r) + getsum(tp, v + v + 1, tm + 1, tr, l, r);
}

void solve() {
	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	build(1, 1, n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, v;
			cin >> p >> v;                                           
			update(1, 1, n, p, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			if (l & 1) 
				cout << getsum(0, 1, 1, n, l, r) << '\n';
			else                     
				cout << getsum(1, 1, 1, n, l, r) << '\n';
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