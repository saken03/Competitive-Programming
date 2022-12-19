#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 123;

int n;
long long t[MAXN * 4];
int w[MAXN];

void upd(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) upd(v + v, tl, tm, pos, x);
	else upd(v + v + 1, tm + 1, tr, pos, x);
	t[v] = t[v + v] + t[v + v + 1];
}

long long get(int v, int tl, int tr, int l, int r) {
	if (l > r || tl > r || tr < l) return 0;
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r) + 
		get(v + v + 1, tm + 1, tr, l, r);
}

void solve() {
	cin >> n;
	int ind = 1;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			cin >> w[ind];
			upd(1, 1, n, ind, w[ind]);
			ind++;
		}
		else {
			int x;
			cin >> x;
			cout << get(1, 1, n, 1, x - 1) << '\n';
			upd(1, 1, n, x, 0);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}
	
	return 0;
}
