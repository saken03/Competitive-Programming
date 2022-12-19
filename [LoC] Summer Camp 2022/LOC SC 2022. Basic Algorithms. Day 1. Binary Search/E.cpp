/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 14:40:55

***/

#include<bits/stdc++.h>

using namespace std;

int n, k, a[(int)1e5 + 33];

bool could(int x) {
	int planks = 0;
	for (int i = 0; i < n; i++) {
		planks += a[i] / x;
		if (planks >= k) return 1;
	}
	return 0;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 1, r = 1e9, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (could(mid)) {
			ans = max(ans, mid);
			l = mid + 1;	
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';    
//	cout << could(2);
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