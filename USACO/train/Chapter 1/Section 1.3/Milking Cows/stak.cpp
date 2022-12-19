/***
    AUTHOR:    shabylkhan
    CREATED:   28.09.2022 14:36:53

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	queue<string> qu;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s != "-") {
			qu.push(s);
		}
		else qu.pop();
	}

	while (!qu.empty()) {
		cout << qu.front() << ' ';
		qu.pop();
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