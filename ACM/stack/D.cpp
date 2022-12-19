#include<bits/stdc++.h>
using namespace std;

const int INF = 2e9;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}                                                    
	vector<int> mn(n + 2, INF);
	for (int i = n; i >= 1; i--) {
		mn[i] = min(mn[i + 1], a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (mn[mid] < a[i]) {
				l = mid + 1;
				ans = mid;
			}
			else r = mid - 1;
		}
		cout << (ans == -1 ? -1 : ans - i - 1) << ' ';
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