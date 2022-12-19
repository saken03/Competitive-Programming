#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;

	int n = (int)s.size();
	int r = 0, l = n - 1;

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			r = i;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			l = i;
		}
	}

	cout << l - r + 1 << '\n';
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
