/***
    AUTHOR:    shabylkhan
    CREATED:   28.07.2022 15:29:30

***/

#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	int dif1 = abs(a.first - a.second);
	int dif2 = abs(b.first - b.second);
	return dif1 > dif2;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n + n);
	for (int i = 0; i < n + n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);
	long long sum = 0, red = 0, blue = 0;
	for (int i = 0; i < n + n; i++) {
		if ((a[i].first > a[i].second && red < n) || blue == n) {
			red++;
			sum += a[i].first;
		}
		else {
			blue++;
			sum += a[i].second;
		}
	}
	cout << sum << '\n';
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