/***
    AUTHOR:    shabylkhan
    CREATED:   28.07.2022 16:03:21

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, W;
	cin >> n >> W;
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		double c, w;
		cin >> c >> w;
		double semi = c / w;
		a[i] = semi;
	}
	sort(a.rbegin(), a.rend());
	cout.precision(6);
	cout << fixed << a[0] * double(W) << '\n';
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