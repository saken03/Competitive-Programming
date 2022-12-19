/***
    AUTHOR:    shabylkhan
    CREATED:   15.09.2022 08:49:37

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	long long n;
	int k;
	cin >> n >> k;

	long long t = n;
	int cen = 1;
	while (t % 10 == 0) {
		cen *= 10;
		t /= 10;
	}
	cen++;

	long long num = n;
	int rep = 0, last = -1;
	while (num % k != 0) {
		if (last == num % k) {
			cout << -1 << '\n';
			return;	
		}  
		last = num % k;
		num *= cen;
		num += n;
		rep++;
	}
	if (rep == 0) rep++;
	cout << rep << '\n';
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