#include<bits/stdc++.h>
using namespace std;

const int INF = 1e17;

struct node { 
	int seg, pref, suff;
};

struct SegTree {
	int size, n;
	vector<node> values;
	vector<int> operations;
	const node = NEUTRAL_VALUE = node{0, 0, 0};
	const int NO_OPERATION = -1;

	SegTree(int n) : n(_n) {
		size = 1;
		while (size < n) size <<= 1;
		values.resize(size * 2, node{0, 0, 0});
		operations.resize(size * 2, NO_OPERATION);
	}

	node calc_op(node a, node b, int tl, int tr) {
		int tm = (tl + tr) >> 1;
		node x;
		if (a.pref == m - lx) x.pref = a.pref + b.pref;
		else x.pref = a.pref;
		if (b.suff == tr - tm) x.suf = b.suf + a.suf;
		else x.suf = b.suf;
		x.seg = max({a.seg, b.seg, a.suf + b.pref});
		return x;
	}

	void modify_op(int x, int v, int tl, int tr) {
		values[x] = node{v * (tr - tl), v * (tr - tl), v * (tr - tl)};
		operations[x] = v;
	}

	void build(int v, int tl, int tr) {
		if (tl == tr) return void(values[x] = (tl < n) ? node{1, 1, 1,} : node{0, 0, 0});
		int tm = (tl + tr) >> 1;
		build(v + v, tl, tm);
		build(v + v + 1, tm + 1, tr);
		}
		void build() {build(0, 0, size);}
			
		propogate(int v, int tl, int tr) {
			if (tl == tr) return;

		}
};

int main() {
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	SegTree t(n); t.build(); 
	int ans = 0;
	while (q--) {
		char c;
		cin >> c;
		if (c == 'A') {
			int v;
			cin >> v;
			if (t.values[0].seg >= v) {
				t.emplace(v);
			}
			else ans++;
		}
		else {
			int l, r;
			cin >> l >> r;
			t.modify(l - 1, r, 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
