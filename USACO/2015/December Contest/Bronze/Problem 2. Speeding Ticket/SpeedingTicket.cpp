/***
    AUTHOR:    shabylkhan
    CREATED:   23.05.2022 22:30:18

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	int start = 0;
	vector<int> limit(100);
	for (int i = 0; i < n; i++) {
		int length, speed;
		cin >> length >> speed;
		for (int j = start; j < start + length; j++) {
			limit[j] = speed;
		}
		start += length;
	}

	start = 0;
	vector<int> bessie(100);
	for (int i = 0; i < m; i++) {
		int length, speed;
		cin >> length >> speed;
		for (int j = start; j < start + length; j++) {
			bessie[j] = speed;
		}
		start += length;
	}

	int worst = 0;
	for (int i = 0; i < 100; i++) {
		worst = max(worst, bessie[i] - limit[i]);
	}
	cout << worst << '\n';
}

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 