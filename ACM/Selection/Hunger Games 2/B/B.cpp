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

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);

/*
	vector<int> b = query(1, 1, n, 1, n);
	for (int i : b) cout << i << ' ';
	return;
*/
	while (q--) {
		int l, r;
		cin >> l >> r;                                     
		
		int f = 0, s = 0;
		long long ans = 0;
		
		vector<int> vec = query(1, 1, n, l, r);
		int i = 0, j = (int) vec.size() - 1;
		while (i < j) {
			if (!f) {
				f = vec[i];
				i++;
			}
			if (!s) {
				s = vec[j];
				j--;
			}

			long long x = min(f, s);
			ans += x;
			f -= x;
			s -= x;
		}

		cout << ans + max(f, s) << '\n';
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