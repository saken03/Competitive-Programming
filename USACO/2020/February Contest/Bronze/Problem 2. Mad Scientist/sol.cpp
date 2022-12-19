/***
    AUTHOR:    shabylkhan
    CREATED:   31.07.2022 22:54:40

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;

	int ans = 0, cringe = 0;
	for (int i = 0; i < n; i++) {
		if (cringe && a[i] == b[i]) {
			ans++;
			cringe = 0;
		}
		if (a[i] != b[i]) {
			cringe = 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 