/***
    AUTHOR:    shabylkhan
    CREATED:   12.06.2022 11:43:33

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int W = 0;
	string ans = "";
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;

		if (W > w) {//reverse
			int bin = W - w;
			for (int m = 0; m < 27; m++) {
				if ((1 << m) == bin) {
					if (m == 26) {
						ans += " ";
						W -= (1 << 26);
						break;
					}

					char c = m + 'a';
					ans += c;
					W -= (1 << m);
				}
			}
		}
		else {
			int bin = w - W;
			for (int m = 0; m < 27; m++) {
				if ((1 << m) == bin) {
					if (m == 26) {
						ans += " ";
						W += (1 << 26);
						break;
					}

					char c = m + 'a';
					ans += c;
					W += (1 << m);
				}
			}
		}
	}
	cout << ans << '\n';
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