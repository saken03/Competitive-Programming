/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 20:59:31

***/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
	int n, H;
	cin >> n >> H;
	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int k = 0; k <= 2; k++) {
		ll h = H;
		int ind = 0, up = 0;
		while (ind < n) {
			if (a[ind] < h) h += a[ind++] >> 1;
			else if (up == 3) break;
			else {
				if (up == k) h *= 3;
				else h *= 2;
				up++;
			}
		}
		ans = max(ans, ind);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
