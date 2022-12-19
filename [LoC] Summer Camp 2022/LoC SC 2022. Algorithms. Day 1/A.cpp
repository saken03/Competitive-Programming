/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 13:58:23

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int left = c - a - b;
	int xa = 0, xb = 0;
	while (a + xa < 150 && left) {
		xa++;
		left--;
	}
	while (b + xb < 150 && left) {
		xb++;
		left--;
	}
	cout << xa << ' ' << xb << '\n';
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