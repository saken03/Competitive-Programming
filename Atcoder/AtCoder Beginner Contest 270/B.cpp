/***
    AUTHOR:    shabylkhan
    CREATED:   24.09.2022 18:20:53

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int x, y, z;
	cin >> x >> y >> z;

	if (y < 0) {
		x = -x;
		y = -y;
		z = -z;
	}

	if (x < y) cout << abs(x);
	else {
		if (z < y) cout << abs(z) + abs(x - z);
		else cout << -1;
	}
	cout << '\n';
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