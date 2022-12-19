/***
    AUTHOR:    shabylkhan
    CREATED:   05.11.2022 15:47:32

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 100;

struct node {
	int a, b, c;
};

node t[MAXN * 4];
int a[MAXN];

node combine(node n1, node n2) {
	int t = min(n1.b, n2.c);
	node nw;
	nw.a = n1.a + n2.a + t;
	nw.b = n1.b + n2.b - t;
	nw.c = n1.c + n2.c - t;
	return nw;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].a = 0;
		if (a[tl] == 1) t[v].b = 1;
		else t[v].c = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = combine(t[v + v], t[v + v + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
	node zero;
	zero.a = zero.b = zero.c = 0;
	if (l > r || tl > r || tr < l) return zero;     
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return combine(get(v + v, tl, tm, l, r), get(v + v + 1, tm + 1, tr, l, r));
}

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '(') a[i] = 1;
		else a[i] = -1;
	}	

	build(1, 1, n);   
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		 int l, r;
		 cin >> l >> r;
		 cout << get(1, 1, n, l, r).a * 2 << '\n';
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