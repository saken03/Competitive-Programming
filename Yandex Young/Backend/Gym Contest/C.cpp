/***
    AUTHOR:    shabylkhan
    CREATED:   07.06.2022 17:37:47

***/

#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	vector<int> b(n);
	b = a;
	sort(b.begin(), b.end());
	unordered_map<int, int> cost;

	bool sp = 0;
	if (k > n - k) {
		sp = 1;
	}

	for (int i = 0; i < n; i++) {
		// find answer for b[i]
		if (sp) {
			long long ans = abs(sum - b[i] * n);
			int l = 0, r = n - 1, c = 0;
			while (c != n - k) {
				if (l == i) ans += abs(b[i] - b[r]), c++, r--;
				else if (r == i) ans += abs(b[i] - b[l]), c++, l++;
				else {
					int lc = abs(b[i] - b[l]);
					int rc = abs(b[i] - b[r]);
					if (lc > rc) {
						ans -= lc;
						l++;
					}
					else {
						ans -= rc;
						r--;
					}
					c++;
				} 
			}
			cost[b[i]] = ans;
			continue;
		}

		int l = i - 1, r = i + 1, c = 0;
		long long ans = 0;
		while (c != k) {
			if (l < 0) ans += abs(b[i] - b[r]), c++, r++;
			else if (r >= n) ans += abs(b[i] - b[l]), c++, l--;
			else {
				int lc = abs(b[i] - b[l]);
				int rc = abs(b[i] - b[r]);
				if (lc < rc) {
					ans += lc;
					l--;
				}
				else {
					ans += rc;
					r++;
				}
				c++;
			}
		}	
		cost[b[i]] = ans;
	}

	for (int i : a) {
		cout << cost[i] << ' ';
	}
	return 0;
} 