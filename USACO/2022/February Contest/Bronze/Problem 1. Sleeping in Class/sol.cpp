/***
    AUTHOR:    shabylkhan
    CREATED:   10.07.2022 14:05:54

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int d = n; d >= 1; d--) {
		if (sum % d == 0) {
			int tar = sum / d;
			int cur = 0;
			bool good = 1;
			for (int i = 0; i < n; i++) {
				cur += a[i];
				if (cur == tar) {
					cur = 0;
				}
				if (cur > tar) {
	      	good = 0;
	      	break;
				}
			}         
			if (good) {
				cout << n - d << '\n';
				return;
			}
		}
	}
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