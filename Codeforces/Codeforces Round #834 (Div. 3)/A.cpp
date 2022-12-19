/***
    AUTHOR:    shabylkhan
    CREATED:   13.10.2022 20:59:31

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (s[0] == 'Y'){}
	else if (s[0] == 'e') s = 'Y' + s;
	else if (s[0] == 's') s = "Ye" + s;
	else {
		cout << "NO\n";
		return;
	}
	bool good = 1;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = i % 3 == 0 ? 'Y' : i % 3 == 1 ? 'e' : 's';
		if (s[i] != c) {
			good = 0;
			break;
		}
	}
	cout << (good ? "YES" : "NO") << '\n';
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
