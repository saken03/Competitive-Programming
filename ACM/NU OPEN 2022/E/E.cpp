#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 2e5 + 121;

int a[MAXN];

void solve() {
	int n;
	cin >> n;

	map<int, bool> pos;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = 1;
	}
	int m;
	cin >> m;
	while (m--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			int dif = 0;
			for (int i = r; i >= l; i--) {
			  if (pos[i]) break;
				dif++;
			}
			for (int i = r; i >= l; i--) {
				if (pos[i]) {
					pos[i] = 0;
					pos[i + dif] = 1;
				}
			}
		}
		else {
			int sum = 0;
			for (int i = l; i <= r; i++) {
				if (pos[i]) sum++;
			}
			cout << sum << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 