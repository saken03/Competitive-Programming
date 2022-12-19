/***
    AUTHOR:    shabylkhan
    CREATED:   28.10.2022 17:39:11

***/

#include<bits/stdc++.h>

using namespace std;

long long SUM(long long n) {
	return (n * 1ll * n + n) >> 1ll;
}

void solve() {
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1 && a[0] <= k) {
		cout << SUM(a[0]) << '\n';
		return;
	}

	else if (n == 1 && a[0] > k) {
		cout << SUM(a[0]) - SUM(a[0] - k) << '\n';
		return;
	}

	sort(a.rbegin(), a.rend());
	long long r = a[0], l = a[1];
	long long sum = k / (r - l + 1) * (SUM(r) - SUM(l - 1));
	k %= r - l + 1;
	cout << sum + SUM(r) - SUM(r - k) << '\n';
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