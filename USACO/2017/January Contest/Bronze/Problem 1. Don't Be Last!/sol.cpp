/***
    AUTHOR:    shabylkhan
    CREATED:   31.07.2022 22:37:44

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	map<string, int> raw;
	for (int i = 0; i < n; i++) {
		string a;
		int b;
		cin >> a >> b;
		raw[a] += b;
	}

	vector<pair<int, string>> cows;
	for (pair<string, int> t : raw) {
		cows.push_back({t.second, t.first});
	}
	sort(cows.begin(), cows.end());

	int ind = 0;
	if ((int)cows.size() == 7) {
		while (ind < (int)cows.size() && cows[ind].first == cows[0].first) {
			ind++;
		}
	}

	if (ind < (int)cows.size() && (ind + 1 == (int)cows.size() || cows[ind].first != cows[ind + 1].first)) {
		cout << cows[ind].second << '\n';
	}
	else {
		cout << "Tie\n";
	}
}

int main() {
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 