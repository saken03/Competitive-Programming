/***
    AUTHOR:    shabylkhan
    CREATED:   21.07.2022 22:19:17

***/

#include<bits/stdc++.h>

using namespace std;

int t[700500], a[200500];

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

int getmax(int v, int tl, int tr, int l, int r) {
	if (l > r || l > tr || r > tl) {
		return 0;
	}
	if (l <= tl && tr <= r) {
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	return max(getmax(v + v, tl, tm, l, min(r, tm)), getmax(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}

bool reach(int xs, int ys, int xf, int yf, int k) {
	int leftx = xf - xs;
	int lefty = yf - ys;

	leftx = abs(leftx);
	lefty = abs(lefty);

	if ((leftx / k) * k != leftx) return 0;
	if ((lefty / k) * k != lefty) return 0;

	return 1;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int xs, ys, xf, yf, k;
		cin >> ys >> xs >> yf >> xf >> k;
		int mx = getmax(1, 1, n, ys, yf);
		if (xs > mx) {
			if (reach(xs, ys, xf, yf, k)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else {
			int left = mx + 1 - xs;
			xs += (left / k) * k;
			if (xs < mx) xs += k;
			if (reach(xs, ys, xf, yf, k)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
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