/***
    AUTHOR:    shabylkhan
    CREATED:   07.06.2022 11:05:30

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	map<int, int> m;
	bool ok = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i - 1] > a[i]) ok = 1;
		m[a[i]]++;
	}
	
	if (ok) {
		cout << -1 << '\n';
		return;
	}

	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
	}

	n = (int)s.size();
	int ans = 0;

	for (auto it = s.begin(); it != s.end(); it++) {
		auto tt = it;
		tt++;
		if (tt == s.end()) break;
		ans += *tt - *it;
	}
	cout << ans << '\n';
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