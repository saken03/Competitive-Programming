/***
    AUTHOR:    shabylkhan
    CREATED:   09.09.2022 21:18:59

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5; 

int t[4 * MAXN];
int a[MAXN];

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

void update(int v, int tl, int tr, int pos) {
	if (tl == tr) {
	  t[v] ^= 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) 
		update(v + v, tl, tm, pos);
	else 
		update(v + v + 1, tm + 1, tr, pos);
	t[v] = t[v + v] + t[v + v + 1];
}

int query(int v, int tl, int tr, int k) {
	if (tl == tr) {
		return tl;
	}
	int tm = (tl + tr) >> 1;
	if (k < t[tm]) {
		return query(v + v, tl, tm, k);
	}
	else {
		return query(v + v + 1, tm + 1, tr, k - t[tm]);
	}
}

void solve() { 
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int pos;
			cin >> pos;
			update(1, 0, n - 1, pos);
		}
		else {
			int k;
			cin >> k;
			cout << query(1, 0, n - 1, k) << '\n';
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