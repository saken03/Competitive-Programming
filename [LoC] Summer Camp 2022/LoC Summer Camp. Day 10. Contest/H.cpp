/***
    AUTHOR:    shabylkhan
    CREATED:   29.07.2022 14:59:37

***/

#include<bits/stdc++.h>

using namespace std;

int mx, a, b, c;

void rec(int n, int k, int cn = 0) {
	if (n < 0) return;
	if (n % k == 0) {
		mx = max(mx, cn + n / k);
	}
}

void solve() {
	int n;
	cin >> n >> a >> b >> c;
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	rec(n, a);
	rec(n, b);
	rec(n, c);
	rec(n - a, b, 1);
	rec(n - a, c, 1);
	rec(n - b, a, 1);
	rec(n - b, c, 1);
	rec(n - c, a, 1);
	rec(n - c, b, 1);
	rec(n - a - b, c, 2);
	rec(n - a - c, b, 2);
	rec(n - b - c, a, 2);
	cout << mx;
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