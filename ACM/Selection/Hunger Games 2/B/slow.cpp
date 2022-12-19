/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 09:58:25

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int a[MAXN];

void solve() {
	int n, q;
	cin >> n >> q;
	map<int, bool> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m[a[i]] = 1;
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;

		if (n == 2) {
			cout << max(a[1], a[2]) << '\n';
		}
		else if (n == 3) {
			int ga = 0, gb = 0;
			for (int j = l; j <= r; j++) {
				if (ga <= gb) ga += a[i];	
			}

		}
		else if (m.size() == 1) {
			int len = r - l + 1;
			if (len == 1) cout << 1 << '\n';
			else cout << len / 2 + len % 1 << '\n';
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