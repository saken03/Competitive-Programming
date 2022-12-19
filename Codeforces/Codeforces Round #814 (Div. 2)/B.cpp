/***
    AUTHOR:    shabylkhan
    CREATED:   16.08.2022 21:10:09

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	int c1 = 0, c2 = 0;
	bool used[n + 1] = {0};
	vector<pair<int, int>> pr;
	vector<int> l, p;
	for (int i = 1; i <= n; i++) {
		if ((i + k) % 4 == 0) pr.emplace_back(i, 0), used[i] = 1;
		else if (i % 4 == 0) pr.emplace_back(0, i), used[i] = 1;
		if ((i + k) % 4 == 2) c1++, l.push_back(i), used[i] = 1;
		else if (i % 4 == 2) c2++, p.push_back(i), used[i] = 1;
	}

	if (k != 0 && (int) pr.size() >= n / 2) {
		cout << "YES\n";
		int ind = 1, ops = 0;
		for (auto& i : pr) {
			for (; ind <= n; ind++) {
				if (!used[ind]) {
					used[ind] = 1;
					if (i.first == 0) cout << ind << ' ';
					else cout << i.first << ' ';
					if (i.second == 0) cout << ind << '\n';
					else cout << i.second << '\n';
					ops++;
					break;
				}
			}
		}
	}
	n /= 2;
	int ops = n - (int) pr.size();
	n -= (int) pr.size();
	if (k != 0 && c1 + c2 >= n) {
			int i = 0, j = 0;
			while (ops && i < (int) l.size() && j < (int) p.size()) {
				cout << l[i] << ' ' << p[j] << '\n';
				ops--;
				i++;
				j++;                   

			}
		}

	else cout << "NO\n";
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