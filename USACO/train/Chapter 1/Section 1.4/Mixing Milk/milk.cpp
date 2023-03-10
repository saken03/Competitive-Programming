/***
PROB: milk
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
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

void solve() {                                              
	int n, m;
	cin >> n >> m;
	vector<int> p(m), a(m);
	multiset<pair<int, int>> s;
	for (int i = 0; i < m; i++) cin >> p[i] >> a[i], s.insert(mp(p[i], a[i]));
	int cost = 0;
	for (auto it : s) {
		int amount = min(it.s, n);
		cost += it.f * amount;
		n -= amount;
		if (!n) break;
	}
	cout << cost << '\n';
}

int main() {
	setIO("milk");

	solve();

	return 0;
}   
