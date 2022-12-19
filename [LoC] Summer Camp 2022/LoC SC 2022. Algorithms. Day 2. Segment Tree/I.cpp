/***
    AUTHOR:    shabylkhan
    CREATED:   12.10.2022 19:55:55

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

int n, t[MAXN * 4];

void update(int v, int tl, int tr, int pos, int h) {
	if (tl == tr) {
		t[v] = h;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (tm <= pos) {
		update(v + v, tl, tm, pos, h);
	}
	else {
		update(v + v + 1, tm + 1, tr, pos, h);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;

	while (q--) {
		int tp;
		cin >> tp;

		if (tp == 1) {
			int i, h;
			cin >> i >> h;
			
			update(1, 1, n, i, h);
		}
		else {
			int l, r;
			cin >> l >> r; r--;
			cout << get(1, 1, n, l, r) << '\n';
		}
	}

	return 0;
} 