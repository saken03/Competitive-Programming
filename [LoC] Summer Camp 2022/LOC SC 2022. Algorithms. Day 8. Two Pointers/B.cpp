/***
    AUTHOR:    shabylkhan
    CREATED:   27.07.2022 15:39:12

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i1 = 0;
	for (int i2 = 0; i2 < m; i2++) {
		while (i1 < n && a[i1] < b[i2]) {
			i1++;
		}    
		cout << i1 << ' ';
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