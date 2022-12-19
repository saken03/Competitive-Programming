/***
    AUTHOR:    shabylkhan
    CREATED:   29.10.2022 15:09:59

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	vector<int> a(4);
	for (int i = 0; i < 4; i++) cin >> a[i];
	int b;
	cin >> b;
	sort(a.begin(), a.end());
	if (a[0] < a[1]) a[0] += b;
	if (a[0] == a[1] && a[2] == a[3] && a[1] == a[2]) {
		cout << 1 << '\n';
	}
	else cout << 0 << '\n';
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