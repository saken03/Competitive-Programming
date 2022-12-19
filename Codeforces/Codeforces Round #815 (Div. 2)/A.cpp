/***
    AUTHOR:    shabylkhan
    CREATED:   18.08.2022 19:34:38

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
  long long a, b, c, d;
	cin >> a >> b >> c >> d;

	double A = a, B = b, C = c, DD = d;
	long long D = 1, N = 1;
	if (A / B == C / DD) {
		cout << 0 << '\n';
		return;
	}

	long long den = a * c / __gcd(a, c);
	long long num = b * d / __gcd(b, d);
	int ans = 0;
	if (a != den) {
		if (a < den) D *= den / a;
		else N *= den / a;
	}
	if (c != den) {
		if (c < den) D *= den / c;
		else N *= den / c;
	}  
	if (b != num) {
		if (b < num) N *= num / b;
		else D *= num / b;
	}
	if (d != num) {
		if (d < num) N *= num / d;
		else D *= num / d;
	}
	if (D % N == 0) D /= N;
	if (D != 1) ans++;
	if (N != 1) ans++; 
	cout << ans << '\n';
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