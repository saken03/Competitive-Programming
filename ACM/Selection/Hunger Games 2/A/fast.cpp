/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 09:40:40

***/

#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), pref(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	pref[0] = a[0];
	for (int i = 1; i < n; i++) pref[i] += pref[i - 1] + a[i];

	long long need = sum / 3, A = 0, ans = INF;
	for (int i = 0; i < n; i++) {
		if (pref[i] >= need) {
			A = pref[i];
			for (int j = i + 1; j < n - 1; j++) {
			// B - [i + 1 ... j] , C - [j + 1 ... n - 1]
				long long mx = 0, mn = INF;
				long long B = pref[j] - pref[i], C = pref[n - 1] - pref[j]; 
				mx = max(mx, max(B, max(A, C)));
				mn = min(mn, min(B, min(A, C)));
				ans = min(ans, mx - mn);
				}
				cout << ans << '\n';
				return;
		}
	}
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