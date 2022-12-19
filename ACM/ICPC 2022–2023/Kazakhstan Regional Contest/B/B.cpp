/***
    AUTHOR:    shabylkhan
    CREATED:   29.10.2022 18:29:40

***/

#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

template<typename T>
int sz(T a) {
//	return abs(a.se.fi - a.fi.fi) + abs(a.se.se - a.fi.se);
	if (a.fi.fi == a.se.fi) return a.se.se - a.fi.se + 1;
	else return a.se.fi - a.fi.fi + 1; 
}

template<typename T>
pair<int, int> intersect(T a, T b) {
	int ad, bd;
	if (a.fi.fi == a.se.fi) ad = 0;
	if (a.fi.se == a.se.se) ad = 1;
	if (b.fi.fi == b.se.fi) bd = 0;
	if (b.fi.se == b.se.se) bd = 1;

	if (ad == bd) {
		if (ad == 0) {
			if (a.fi.se < b.fi.se && b.fi.se <= a.se.se) {
				return {a.fi.fi, b.fi.se};
			}
			else return {-1, -1};
		}
		else {
			if (a.fi.fi < b.fi.fi && b.fi.fi <= a.se.fi) {
				return {a.fi.se, b.fi.fi};	
			}
			else return {-1, -1};
			}
	}
	else {
		if (a.fi.fi >= b.fi.fi || a.se.fi <= b.fi.fi) return {-1, -1};
		return {a.fi.fi, b.fi.se};	
	}
}

template<typename T>
int len(pair<int, int> a, T b) {
	if (b.fi.fi == b.se.fi) {
		int mx = 0;
		if (b.fi.se < a.se) mx = max(mx, a.se - b.fi.se);
		if (b.se.se > a.se) mx = max(mx, b.se.se - a.se);
		return mx;
	}
	else {
		int mx = 0;
		if (b.fi.fi < a.fi) mx = max(mx, a.fi - b.fi.fi);
		if (b.se.fi > a.fi) mx = max(mx, b.se.fi - a.fi);
		return mx;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
 	vector<vector<char>> c(n, vector<char> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}

	vector<pair<pair<int, int>, pair<int, int>>> v;

	for (int i = 0; i < n; i++) {
		int cur = 0, l = -1;
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '.') {
				if (l == -1) {
					l = j;
				}
				cur++;
			}
			else if (cur) {
				v.push_back({{i, l}, {i, j - 1}});
				l = -1;
				cur = 0;
			}
		}
		if (cur) v.push_back({{i, l}, {i, m - 1}});
	}

	for (int j = 0; j < m; j++) {
		int cur = 0, l = -1;
		for (int i = 0; i < n; i++) {
			if (c[i][j] == '.') {
				if (l == -1) l = i;
				cur++;
			}
			else if (cur) {
				v.push_back({{l, j}, {i - 1, j}});
				l = -1;
				cur = 0;
			}
		}
 		if (cur) v.push_back({{l, j}, {n - 1, j}});
	}

	int MX = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = i + 1; j < (int)v.size(); j++) {
			pair<int, int> inter = intersect(v[i], v[j]);
			if (inter.fi == -1 && inter.se == -1) {
				MX = max(MX, sz(v[i]) + sz(v[j]));	
			}
			else {
		//		cout << inter.fi << ' ' << inter.se << '\n';
				MX = max(MX, max(sz(v[i]) + len(inter, v[j]), sz(v[j]) + len(inter, v[i])));
			}
		}
	}
	cout << MX << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 