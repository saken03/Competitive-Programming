/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 15:36:00

***/

#include<bits/stdc++.h>

using namespace std;

long long n;
int a, b, c, d;

bool check(long long t) {
	if (n <= t * 1ll * (a + c)) return 1;
	return 0;
}

void solve() {         
	cin >> n >> a >> b >> c >> d;
	long long t = -1, l = 1, r = (int) 2e10;
	while (l <= r) {
		long long mid = (l + r) >> 1ll;
		if (check(mid)) {
			t = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << (t - 1) * 1ll * (b + d) << '\n';
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