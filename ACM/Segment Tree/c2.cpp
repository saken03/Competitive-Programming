#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 123;

int a[MAXN], t[MAXN * 4];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {cin >> a[i];}
	int res = 0;
	for (int i = n; i > 0; i--) {
		res += get(1, 1, n, a[
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
