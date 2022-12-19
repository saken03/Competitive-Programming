/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 16:36:59

***/

#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;
bool used[140];

void generate() {
	if ((int)a.size() == k) {
		for (int x : a) cout << x << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i] && ((int)a.size() == 0 || a[(int)a.size() - 1] <= i + 1)) {
				used[i] = 1;
				a.push_back(i);
				generate();
				used[i] = 0;
				a.pop_back();
		}
	}
}

void solve() {
	cin >> n >> k;
	generate();
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