/***
    AUTHOR:    shabylkhan
    CREATED:   25.06.2022 13:09:18

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, b;
	cin >> n >> b;

	vector<int> x(n), y(n);
	set<int> v, h;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		v.insert(x[i] + 1);
		h.insert(y[i] + 1);
	}

	int ans = n;
	for (int ver : v) {
		for (int hor : h) {
			int top_left = 0,
					top_right = 0,
					bottom_left = 0,
					bottom_right = 0;
			
			for (int i = 0; i < n; i++) {
				if (x[i] < ver && y[i] < hor) {
					bottom_left++;
				}
				else if (x[i] < ver && y[i] > hor) {
					top_left++;
				}
				else if (x[i] > ver && y[i] < hor) {
					bottom_right++;
				}
				else {
					top_right++;
				}
			}

			ans = min(ans, max({bottom_left, bottom_right, top_left, top_right}));
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 