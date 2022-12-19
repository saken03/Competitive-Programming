/***
    AUTHOR:    shabylkhan
    CREATED:   29.09.2022 22:21:44

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	int A = 0, B = 0, C = 0;
	for (int m = 0; m < (1 << n); m++) {
		vector<int> c1, c2;
		for (int i = 0; i < n; i++) {
			if (m & (1 << i)) c1.push_back(i);
			else c2.push_back(i);
		} 
		int a = 0, b = 0, c = 0;
		bool nin = 0; // n is in a or b
		for (int i = 0; i < n / 2; i++) {
			if (c1[i] < c2[i]) b++;
			else if (c1[i] > c2[i]) a++;
			else c++; 
		}   

		if (a > b || (a == b && nin == 0)) A++;
		else if (a < b) B++;
		else C++;
	}
	cout << A << ' ' << B << ' ' << C << '\n';
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