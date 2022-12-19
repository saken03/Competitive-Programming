/***
    AUTHOR:    shabylkhan
    CREATED:   29.07.2022 14:54:00

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> deg(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;    
		deg[a]++;
		deg[b]++;
	}

	set<int> s;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			s.insert(i);
		}
	}
	cout << s.size() << '\n';
	for (auto i : s) {
		cout << i << ' ';
	}
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