/***
    AUTHOR:    shabylkhan
    CREATED:   23.07.2022 12:59:34

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int x;
		cin >> x;
		m[s] += x;
	}

	vector<pair<int, string>> v;

	for (auto i : m) {
		v.push_back({i.second, i.first});
	}
	
	sort(v.begin(), v.end());

	if (v[0].first == 0) {
		cout << 0 << '\n';
		return;
	}
	int f = v[0].first, ind = -1;
	for (int i = 1; i < (int)v.size(); i++) {
		if (f != v[i].first) {
			f = v[i].first;
			ind = i;
			break;
		}
	}
	if (ind == (int)v.size()) {
		cout << "Tie\n";
		return;
	}
	cout << v[ind].second << '\n';
}

int main() {
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	solve();
	return 0;
} 