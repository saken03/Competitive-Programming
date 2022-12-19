/***
    AUTHOR:    shabylkhan
    CREATED:   31.10.2022 19:30:40

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;
const int MAXA = 1e6 + 123;
const long long INF = 1e12;

int n, m;
bool marked[MAXN];
long long t[MAXN * 4];

void push(int v, int tl, int tr) {
//	if (tl == tr) return;
	if (marked[v]) {
		t[v + v] = t[v + v + 1] = t[v];
		t[v] = (tr - tl + 1) * t[v];
		marked[v] = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int x) {
	if (tl > r || l > tr) return;
	if (l <= tl && tr <= r) {
		t[v] = x;
		marked[v] = 1;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	push(v, tl, tr);
	update(v + v, tl, tm, l, min(r, tm), x);
	update(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x);
	t[v] = t[v + v] + t[v + v + 1];
	push(v, tl, tr);
}

long long get(int v, int tl, int tr, int l, int r) {
	if (l > r || tl > r || l > tr) return 0;
	push(v, tl, tr);
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r) + 
		get(v + v + 1, tm + 1, tr, l, r);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		char c;
		int l, r, x;
		cin >> c;
		if (c == 'A') {
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
		else {
			cin >> l >> r;
			cout << get(1, 1, n, l, r) << '\n';
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
