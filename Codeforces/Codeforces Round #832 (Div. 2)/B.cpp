/***
    AUTHOR:    shabylkhan
    CREATED:   04.11.2022 20:44:11

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	string s = "";
	for (int i = 0; i < n; i++) s += "ban";

	if (n == 1) {
		cout << 1 << '\n' << 1 << ' ' << 2 << '\n';
	}
	else {
/*		cout << n - (n + 1) / 3 << '\n';
		int i = 1, j = 3 * n;
		for (int c = 1; c <= n - (n + 1) / 3; c++) {
			cout << i << ' ' << j << '\n';
			swap(s[i - 1], s[j - 1]);
			i++;
			if (i % 3 == 0) i++;
			j -= 3;
		}
*/
		vector<pair<int, int>> ans;
		int i = 2, j = 3 * n;
		while (i < j) {
			ans.push_back({i, j});
			i += 3;                                                         
			if (i % 3 == 0) i++;
			j -= 3;
		}

		cout << (int)ans.size() << '\n';
		for (auto i : ans) {
			cout << i.first << ' ' << i.second << '\n';
		}
	}
//	cout << s << '\n';
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