/***
    AUTHOR:    shabylkhan
    CREATED:   04.11.2022 22:03:25

***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 123;

int a[MAXN];

bool bit(int x, int p) {
	return (x & (1 << p));
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int s1 = 0;  
		bool ok = 0;
		for (int b = 0; b < 30; b++) {
			for (int i = l; i <= r; i++) {
		  	if (bit(a[i], b)) s1++;	
		  }
		  if (s1 & 1) {
				cout << -1 << '\n';
				ok = 1;
				break;
			}
		}
    if (ok) continue;
		else {
			if ((r - l + 1) & 1) cout << 2;
			else cout << 1;
			cout << '\n';
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