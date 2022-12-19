/***
    AUTHOR:    shabylkhan
    CREATED:   16.06.2022 21:33:10

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << (a[0] == 0 ? "YES\n" : "NO\n");
		return;
	}

	while (a[n - 1] == 0) {
		n--;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum < 0) {
			cout << "NO\n";
			return;
		}
		if (sum == 0) {
			if (i == n - 1) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
			return;
		}
	}
	cout << "NO\n";
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