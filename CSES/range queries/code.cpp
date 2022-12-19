
/***
    AUTHOR:    shabylkhan
    CREATED:   31.10.2022 19:30:40

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 123;
const int MAXA = 1e6 + 123;

int n, q, a[MAXN];
long long t[MAXN * 4];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = t[v + v] + t[v + v + 1];
}

void update(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) update(v + v, tl, tm, pos, x);
	else update(v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

long long getsum(int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl || l > r) return 0;
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return getsum(v + v, tl, tm, l, r) +
		getsum(v + v + 1, tm + 1, tr, l, r);
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) update(1, 1, n, l, r);
		else cout << getsum(1, 1, n, l, r) << '\n';
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
