#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
*/
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

vector<int> a;

void compress(vector<int>& a) {
	vector<int> b = a;
	sort(b.begin(), b.end());
	map<int, int> m;
	int cnt = 0;
	for (int i = 0; i < sz(b); i++) {
		m[b[i]] = cnt;
		cnt++;
	}
	for (int i = 0; i < sz(a); i++) {
		a[i] = m[a[i]];
	}
}

int t[50005 * 4];

void upd(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		t[v]++;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) upd(v + v, tl, tm, pos);
	else upd(v + v + 1, tm + 1, tr, pos);
	t[v] = t[v + v] + t[v + v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r || tl > r || l > tr) return 0;
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return get(v + v, tl, tm, l, r) + get(v + v + 1, tm + 1, tr, l, r);
}

void solve() {
	int n;
	cin >> n; a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	compress(a);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += get(1, 1, n, a[i] + 1, n);
		upd(1, 1, n, a[i]);
	}
	cout << cnt;
}

int main() {
	setIO("inverse");

	solve();
	
	return 0;
} 











