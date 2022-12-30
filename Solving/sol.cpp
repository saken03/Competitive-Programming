#include <bits/stdc++.h>
using namespace std;

int lis = 0;
pair<int, int> a[100000];
set<int> s;

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n, greater<pair<int, int>>());
	cout << '\n';
	for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
	return 0;
	// finding the LIS of a reversed array = finding the LDS
	for (int i = 0; i < n; i++) {
		if (s.upper_bound(a[i].second) == s.end()) lis++;
		else s.erase(s.upper_bound(a[i].second));
		s.insert(a[i].second);
	}
	cout << lis;
}