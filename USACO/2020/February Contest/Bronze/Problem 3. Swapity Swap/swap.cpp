#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int a[105], a1, a2, b1, b2, res[105];

int next(int x) {
	if (a1 <= x && x <= a2) x = a1 + a2 - x;
	if (b1 <= x && x <= b2) x = b1 + b2 - x;
	return x;
}

void solve() {
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) a[i] = i;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	for (int i = 1; i <= n; i++) {
		int p = 1, cur = next(i);
		while (cur != i) {
			p ++;
			cur = next(cur);
		}
		int k = K % p;
		for (int j = 1; j <= k; j++) cur = next(cur);
		res[cur] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

int main() {
	setIO("swap");

	solve();

	return 0;
}