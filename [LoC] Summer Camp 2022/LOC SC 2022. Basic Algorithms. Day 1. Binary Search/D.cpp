/***
    AUTHOR:    shabylkhan
    CREATED:   19.07.2022 14:32:22

***/

#include<bits/stdc++.h>

using namespace std;

int n;

bool enough(int v) {
	long long sum = v;
	for (int i = 2; i <= v; i++) {
		sum += v / i;
	}
	if (sum >= n) return 1;
	return 0;
}

void solve() {
	cin >> n;
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (enough(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';
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