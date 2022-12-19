1/***
    AUTHOR:    shabylkhan
    CREATED:   31.10.2022 19:30:40

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 123;
const int MAXA = 1e6 + 123;

long long n, m, a[MAXN], d[MAXA + 500];
long long t1[MAXN * 4], t2[MAXN * 4];

void update(int v, int tl, int tr, int i, int x) {
	if (tl == tr) {
		t1[v] = x;
		t2[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;                   
	if (i <= tm) update(v + v, tl, tm, i, x);
	else update(v + v + 1, tm + 1, tr, i, x);
	t1[v] = t1[v + v] + t1[v + v + 1];
	t2[v] = max(t2[v + v], t2[v + v + 1]);
}

vector<int> pp;

void find(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l || t2[v] <= 2) return;
	if (tl == tr) pp.push_back(tl);
	else {
		int tm = (tl + tr) >> 1;
		find(v + v, tl, tm, l, r);
		find(v + v + 1, tm + 1, tr, l, r);
	}
}

long long get(int v, int tl, int tr, int l, int r) {
	if (r < tl || tr < l || l > r) return 0;
	if (l <= tl && tr <= r) return t1[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r) + get(v + v + 1, tm + 1, tr, l, r);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	while (m--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			pp.clear();   
			find(1, 1, n, l, r);
			for (int i : pp) {
				a[i] = d[a[i]];
				update(1, 1, n, i, a[i]);
			}
		}
		else {                     
			cout << get(1, 1, n, l, r) << '\n';
		}
	}
}

void pre_calc() {
	for (long long i = 1; i <= MAXA; i++) {
		for (long long j = i; j <= MAXA; j += i) {
			d[j]++;
		}        
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pre_calc();     
	int tt = 1;
	while (tt--) {
		solve();
	} 

	return 0;
} 
