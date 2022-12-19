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

const int MAXN = 105;

int outcoming[MAXN];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		outcoming[a]++;
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (outcoming[i] == 0 && ans != -1) {
			cout << -1 << '\n';
			return;
		}
		if (outcoming[i] == 0) ans = i;
	}
	cout << ans + 1 << '\n';
}                                                              

int main() {
	setIO("factory");

	solve();

	return 0;
}