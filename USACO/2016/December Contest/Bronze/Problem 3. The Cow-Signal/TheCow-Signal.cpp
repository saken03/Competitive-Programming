/***
    AUTHOR:    shabylkhan
    CREATED:   28.05.2022 15:35:59

***/

#include<bits/stdc++.h>

using namespace std;

int main() {     
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	int m, n, k;
	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		string signal;
		cin >> signal;
		for (int x = 0; x < k; x++) {
			for (int j = 0; j < n; j++) {
				for (int y = 0; y < k; y++) {
					cout << signal[j];
				}
			}
			cout << '\n';
		}
	}

	return 0;
} 