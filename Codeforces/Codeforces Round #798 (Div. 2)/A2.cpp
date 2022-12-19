/***
    AUTHOR:    shabylkhan
    CREATED:   10.06.2022 22:58:14

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	string ans = "";
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] < b[j]) ans += a[i], i++;
		else ans += b[j], j++;	
	}
	while (i < n) ans += a[i], i++;
	while (j < m) ans += b[j], j++;

	cout << ans[0];
	int cur = 1;
	for (int i = 1; i < (int)ans.size(); i++) {
		if (ans[i] == ans[i - 1]) {
			if (cur == k) {
				continue;
			}
			cout << ans[i];
			cur++;
		}
		else {
			cout << ans[i];
			cur = 1;
		}
	}
	cout << '\n';

/*	int kk = k, i = 0, j = 0, tp = -1, last = -1;
	while (i < n && j < m) {
		if (tp == -1) {
			if (a[i] < b[j]) {
				tp = 0;
				cout << a[i];
				if (last == 1) kk = 0;
				else kk--;
				i++;
			}
			else {
				tp = 1;
				cout << b[j];
				if (last == 1) kk--;
				else kk = 0;
				j++;
			}
			if (!kk) {
				tp ^= 1;
				kk = k;	
			}
			continue;
		}
		
		if (tp == 0) {
			if (a[i] < b[j]) {
				cout << a[i];
				kk--;
				i++;
			}
			else {
				cout << a[i];
				kk = 0;
				i++;
			}
			last = 0;
			tp = -1;
		}
		else {
			if (a[i] > b[j]) {
				cout << b[j];
				kk--;
				j++;
			}
			else {
				cout << b[j];
				kk = 0;
				j++; 
			}
			last = 1;
			tp = -1;
		}
	}
	cout << '\n'; */
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