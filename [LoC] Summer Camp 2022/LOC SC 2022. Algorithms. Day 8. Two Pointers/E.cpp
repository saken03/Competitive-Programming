/***
    AUTHOR:    shabylkhan
    CREATED:   27.07.2022 15:47:02

***/

#include<bits/stdc++.h>

using namespace std;

long long sum(int n) {
	return (n * 1ll * n + n) / 2;
}

void solve() {
	int n;
	long long s;
	cin >> n >> s;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += (i ? a[i - 1] : 0);
	}
	int r = 0, ans = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && a[r] - (l ? a[l - 1] : 0) <= s) {
			r++;
		}
		ans += r - l;
	}
	cout << sum(ans) / 10 << '\n'; 
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