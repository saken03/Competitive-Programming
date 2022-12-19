/***
    AUTHOR:    shabylkhan
    CREATED:   18.07.2022 15:30:09

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'C') s[i] = 'G';
		else if (s[i] == 'T') s[i] = 'A';
		else if (s[i] == 'G') s[i] = 'C';
		else if (s[i] == 'A') s[i] = 'T';
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
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