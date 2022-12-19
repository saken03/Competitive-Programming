/***
    AUTHOR:    shabylkhan
    CREATED:   08.06.2022 21:17:11

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = '0' + s + '1';

	int ans = 0;
	for (int i = 0; i < n + 1; i++) {
		if (s[i] == '0' && s[i + 1] == '1') ans++;
	}
	cout << ans << '\n';
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