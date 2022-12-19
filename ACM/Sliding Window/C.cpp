/***
    AUTHOR:    shabylkhan
    CREATED:   06.10.2022 18:59:14

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n + 1), lr(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		lr[l]++;
		lr[r + 1]--;
	}

	for (int i = 1; i <= n; i++) {
		lr[i] += lr[i - 1];
	}

	sort(lr.begin(), lr.end() - 1);
	sort(a.begin(), a.end());

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += lr[i] * 1ll * a[i];
	}
	cout << sum << '\n';  
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