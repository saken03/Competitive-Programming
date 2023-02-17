#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MAXN = (int)3e5 + 10;

int m, n;
int a[MAXN], t[MAXN * 4];
bool marked[MAXN];

void push(int v) {
	if (marked[v]) {
		t[v + v] = t[v + v + 1] = t[v];
		marked[v + v] = marked[v + v + 1] = 1;
		marked[v] = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r) 
		return;
	if (l == tl && tr == r) {
		t[v] = val;
		marked[v] = 1;
	}
	else {
		push(v);
		int tm = (tl + tr) >> 1;
		update(v + v, tl, tm, l, min(r, tm), val);
		update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
}

int get(int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	push(v);
	int tm = (tl + tr) >> 1;
	if (pos <= tm) 
		return get(v + v, tl, tm, pos);
	else 
		return get(v + v + 1, tm + 1, tr, pos);
}

void solve() {        
	cin >> m >> n;

	vector<int> l(n + 1), r(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		r[a[i]] = i;
	}
	for (int i = m; i >= 1; i--) 
		l[a[i]] = i;

	vector<bool> used(n + 1);
	vector<pair<int, pair<int, int>>> ans;

	for (int i = 1; i <= m; i++) {
		if (!used[a[i]]) {
			update(1, 1, m, l[a[i]], r[a[i]], a[i]);
			ans.pb(mp(a[i], mp(l[a[i]], r[a[i]])));
			used[a[i]] = 1;
		}
	}

	for (int i = 1; i <= m; i++) {
		if (a[i] != get(1, 1, m, i)) {
			cout << -1 << '\n';
			return;
		}
	}

	cout << sz(ans) << '\n';
	for (const auto i : ans)
		cout << i.f << ' ' << i.s.f << ' ' << i.s.s << '\n';
}

int main() {
	setIO("");

	solve();

	return 0;
}   
