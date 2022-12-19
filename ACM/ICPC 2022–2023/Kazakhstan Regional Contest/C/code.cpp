/***
    AUTHOR:    shabylkhan
    CREATED:   29.10.2022 15:30:16

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> port(n, -1), last(n, -1);
	int K = 0;
	for (int i = k; i < n; i++) {
		if (last[K] == -1) {
			port[i] = K;
	  	last[K] = i;
		}
		else {
			port[i] = last[K];
			last[K] = i;
		}
		K++;
		if (K > k) K -= k;
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		int p = i;
		while (p != -1) {
			t += a[p];
			p = port[p];
		}
	}
	cout << t << '\n';
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