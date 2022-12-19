/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 16:32:27

***/

#include<bits/stdc++.h>

using namespace std;

pair<int, int> t[500500];
vector<int> a(500500);

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return a;
	if (a.first > b.first) return b;
	return {a.first, a.second + b.second};
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = {a[tl], 1};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = combine(t[v + v], t[v + v + 1]);		
}

void update(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[v] = {x, 1};
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		update(v + v, tl, tm, pos, x);
	}
	else update(v + v + 1, tm + 1, tr, pos, x);
	t[v] = combine(t[v + v], t[v + v + 1]);
}

pair<int, int> sum(int v, int tl, int tr, int l, int r) {
	if (l > r) return {1e9, 0};
	if (l == tl && tr == r)	return t[v];
	int tm = (tl + tr) >> 1;
	return combine(sum(v + v, tl, tm, l, min(tm, r)), sum(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (m--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int i, v;
			cin >> i >> v;
			update(1, 1, n, i + 1, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			pair<int, int> ans = sum(1, 1, n, l + 1, r);
			cout << ans.first << ' ' << ans.second << '\n';
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