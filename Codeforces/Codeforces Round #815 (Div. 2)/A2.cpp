/***
    AUTHOR:    shabylkhan
    CREATED:   18.08.2022 19:34:38

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
  long long a, b, c, d;
	cin >> a >> b >> c >> d;

	double A = a, B = b, C = c, D = d;
	if (A / B == C / D) {
		cout << 0 << '\n';
		return;
	}
	long long a11, a12, a21, a22;
	a11 = a12 = a21 = a22 = 1;
	a11 *= c;
	a21 *= a;
	a12 *= d;
	a22 *= b;

	if (a11 % a12 == 0 || a21 % a22 == 0) {
		cout << 1 << '\n';
	}
	else cout << 2 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 