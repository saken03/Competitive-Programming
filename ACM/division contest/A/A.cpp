/***
    AUTHOR:    shabylkhan
    CREATED:   26.10.2022 19:33:39

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

int a[MAXN], N;
pair<long long, int> t[MAXN * 4];
int rk, id;

void update(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		t[v].first = tl;
		t[v].second++;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) update(v + v, tl, tm, pos);
	else update(v + v + 1, tm + 1, tr, pos);
	t[v].first = t[v + v].first + t[v + v + 1].first;
	t[v].second = t[v + v].second + t[v + v + 1].second;
}


long long sum(int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl || l > r) return 0;
	if (l <= tl && tr <= r) return t[v].first;
	
	int tm = (tl + tr) >> 1;
	return sum(v + v, tl, tm, l, r) + sum(v + v + 1, tm + 1, tr, l, r);
}

int search(int v, int tl, int tr, int k) {
	if (tl == tr) {
		id = v;
		rk += t[v].second - k;
		return tl;	
	}
	int tm = (tl + tr) >> 1;
	if (k	<= t[v + v].second) {
		rk += t[v + v + 1].second;
		return search(v + v, tl, tm, k);
	}
	else {		
		return search(v + v + 1, tm + 1, tr, k - t[v + v].second);
	}
}

long long query(int x) {
	int l = search(1, 1, MAXN, x);
	long long f = l * (t[id].second - rk);
	rk = 0;
	return sum(1, 1, MAXN, l + 1, MAXN) + f;
}

void solve() {
	int n, q;
	cin >> n >> q;                       
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {	
		update(1, 1, MAXN, a[i]);
	}

	for (int i = 1; i <= q; i++) {
		int tp, x;
		cin >> tp >> x;
		if (tp == 1) {
			update(1, 1, MAXN, x);
		}
		else {
			cout << query(x) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 