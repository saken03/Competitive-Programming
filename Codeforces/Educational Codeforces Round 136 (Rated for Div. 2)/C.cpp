/***
    AUTHOR:    shabylkhan
    CREATED:   29.09.2022 21:10:02

***/

#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;

	int A = 0, B = 0, D = 0;

	for (int a = 0; a <= n / 2; a++) {
		for (int b = 0; b <= n / 2; b++) {
			// # a > b & n in a	
			// # a < b
			// # a = b & n in b
			if (a > b) A++;
			else if (b < a) B++;
			else D++;
		}
	}
	cout << A << ' ' << B << ' ' << D << '\n';
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