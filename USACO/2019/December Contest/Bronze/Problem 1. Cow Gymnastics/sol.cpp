/***
    AUTHOR:    shabylkhan
    CREATED:   05.06.2022 12:30:31

***/

#include<bits/stdc++.h>

using namespace std;

int a[30][30];

void solve() {
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bool I = 0, J = 0;
			for (int kk = 0; kk < k; kk++) {
				bool firstI = 0, firstJ = 0;
				for (int ii = 0; ii < n; ii++) {
					if (a[kk][ii] == i) {
						firstI = 1;
						break;
					}
					if (a[kk][ii] == j) {
						firstJ = 1;
						break;
					}
				}
				if (firstI && firstJ) continue;
				if (firstI) I = 1;
				else J = 1;
			}
			if (I && J) continue;
			if (!(I || J)) continue;
			ans++;	
		}
	}
	cout << ans;
}

int main() {
	
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 