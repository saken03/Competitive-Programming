#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}

	int ans = 0;
	while (s.find(ans) != s.end()) {
		ans++;
	}
	cout << ans;
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

