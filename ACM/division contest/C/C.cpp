/***
    AUTHOR:    shabylkhan
    CREATED:   26.10.2022 20:20:43

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 123;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	if (n <= 1000 && m <= 1000) {
		vector<int> d;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				d.push_back(a[i] + b[j]);
			}
		}
		sort(d.begin(), d.end());
		cout << d[k - 1] << '\n';	
		return;
	}

	map<int, int> m1, m2;
	for (int i : a) m1[i]++;
	for (int i : b) m2[i]++;

	if ((int)m1.size() == 1 && (int)m2.size() == 1) {
		cout << 2 << '\n';
	}

	else if ((int)m1.size() == 1) {
		for (int j = 0; j < m; j++) {
			if (k < n) {
				cout << 1 + b[j] << '\n';
				return;
			}
			k -= n;
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