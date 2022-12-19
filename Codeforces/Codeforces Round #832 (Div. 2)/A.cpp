/***
    AUTHOR:    shabylkhan
    CREATED:   04.11.2022 20:38:08

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;	
	cin >> n;
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) s1 += x;
		else s2 += x;
	}

	s1 = abs(s1);
	s2 = abs(s2);
	cout << max(abs(s1 - s2), abs(s2 - s1)) << '\n';
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