/***
    AUTHOR:    shabylkhan
    CREATED:   01.10.2022 22:50:53

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n); 
  set<int> d;
  for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) { int x; cin >> x; }
	for (int i = 0; i < m; i++) { int x; cin >> x; d.insert(x); } 

	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = d.lower_bound(a[i]);
		if (it != d.end()) ans++, d.erase(it);
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