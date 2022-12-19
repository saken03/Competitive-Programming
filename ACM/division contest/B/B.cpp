/***
    AUTHOR:    shabylkhan
    CREATED:   26.10.2022 19:50:52

***/

#include<bits/stdc++.h>

using namespace std;

int g[20][20];

bool bit(int m, int x) {
	return m & (1 << x);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {            
			v.push_back(g[i][j]);
		}
	}

	int nn = (int) v.size();
	long long ans = 0;
	for (int mask = 0; mask < (1 << nn); mask++) {
		long long sum = 0;
		for (int i = 0; i < nn; i++) {
			if (bit(mask, i)) {
				sum += v[i];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';

/*	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	long long ans = 0;
	do
	{
		long long sum = 0;
		for (int i = 0; i < (int)p.size(); i += 2) {
			if (i + 1 < (int)p.size()) {
				int x = g[p[i]][p[i + 1]];
				if (x > 0) sum += x;
			}
		}
		ans = max(ans, sum);
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << '\n';
	*/

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