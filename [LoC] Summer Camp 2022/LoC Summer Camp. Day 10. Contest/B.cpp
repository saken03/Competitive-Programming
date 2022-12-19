/***
    AUTHOR:    shabylkhan
    CREATED:   29.07.2022 14:31:22

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
	sort(a.begin(), a.end());
	long long s = 0;
	for (int i = 0; i < n; i++) {
		s += abs(a[i] - a[0]);
	}
	cout << s << '\n';
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