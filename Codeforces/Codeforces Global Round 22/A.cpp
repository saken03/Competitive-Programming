/***
    AUTHOR:    shabylkhan
    CREATED:   30.09.2022 20:38:28

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> tp(n);
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		cin >> tp[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!tp[i]) a.push_back(x);
		else b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = 0;
	int n1 = (int) a.size(), n2 = (int) b.size();
	if (!n1) {
		for (int i = 0; i < n2; i++) ans += b[i];
		cout << ans << '\n';
		return;
	}
	if (!n2) {
		for (int i = 0; i < n1; i++) ans += a[i];
		cout << ans << '\n';
		return;
	}

	int i = 0, j = 0;
	bool last = 0;
	if (a[0] * 2 < b[0] && n1 < n2) {
		ans = b[0];
		n2--;
		last = 1;
	} 
	else ans = a[0], n1--;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (i < n1 && j < n2) {
		if (!last) {
			ans += 2 * b[j];
			j++;
			last ^= 1;
		}
		else {
			ans += 2 * a[i];
			i++;
			last ^= 1;
		}
	}

	if (i < n1) a[i] += a[i];
	if (j < n2) b[j] += b[j];
	while (i < n1) ans += a[i], i++;
	while (j < n2) ans += b[j], j++;

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