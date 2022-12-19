/***
    AUTHOR:    shabylkhan
    CREATED:   12.09.2022 20:55:07

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	
	int n = (int) s.size();
	queue<int> st[30];
	if (s[0] != s[n - 1]) st[s[n - 1] - 'a'].push(n);

	for (int i = 0; i < n; i++) {
		st[s[i] - 'a'].push(i + 1);
	}

	char a = s[0], b = s[n - 1];
	vector<int> path;

	int ans = 0;
	if (a > b) {
		bool ok = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == a) {
				ok = 1;
				int x = st[s[i] - 'a'].front();
				st[s[i] - 'a'].pop();
				path.push_back(x);
			}
			else if (ok) {
				ans += abs(s[i] - s[i + 1]);
				int x = st[s[i] - 'a'].front();
				st[s[i] - 'a'].pop();
				path.push_back(x);
				if (i == 0) break;
				if (i > 0 && s[i - 1] != b && s[i] == b) break;
			}
		}
	}                             
	else {
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == a) {
				ok = 1;
				int x = st[s[i] - 'a'].front();
				st[s[i] - 'a'].pop();
				path.push_back(x);
			}
			else if (ok) {
				ans += abs(s[i] - s[i - 1]);
			  int x = st[s[i] - 'a'].front();
				st[s[i] - 'a'].pop();
				path.push_back(x);
				if (i == n - 1) break;
				if (i < n - 1 && s[i + 1] != b && s[i] == b) break;
			}
		}
	}
	cout << ans << ' ' << (int) path.size() << '\n';
	for (int i : path) cout << i << ' ';
	cout << '\n';
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