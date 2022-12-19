/***
    AUTHOR:    shabylkhan
    CREATED:   02.11.2022 19:05:27

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

long long a[MAXN], c[MAXN];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = c[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = max(t[v + v], t[v + v + 1]);
}

pair<int, int> search(int v, int tl, int tr, int l, int r, int x) {
	if (l > r || tr < l || r < tl) return {-1, -1};
	if (l <= tl && tr <= r) {
		if (t[v] <= x) return {tl, tr};
	}
	int tm = (tl + tr) >> 1;
}

void solve() {
	int n;
	cin >> n;  
	for (int i = 1; i <= n; i++) {
	  cin >> c[i];
		a[i] = a[i - 1] + c[i];
	}

	build(1, 1, n);

	long long mx = 0;
	for (int i = 1; i <= n; i++) {
		// search(1, i - 1) and search(i + 1, n)
		int l = search(1, 1, n, 1, i - 1, a[i]);
		int r = search(1, 1, n, i + 1, n, a[i]);
		mx = max(mx, a[r] - a[l - 1] - a[i]);
	}
	cout << mx << '\n';
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