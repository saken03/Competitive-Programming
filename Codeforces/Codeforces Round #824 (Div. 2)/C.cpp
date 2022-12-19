/***
    AUTHOR:    shabylkhan
    CREATED:   02.10.2022 20:55:02

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	// next -> s[i] -> d[i];
	// prev -> d[i] -> s[i];
	char c = 'a';
	map<char, char> prev, next;

	for (int i = 0; i < n; i++) {
		while (	c == s[i] || next[c]) {
			c++;
			if (c > 'z') c = 'a';
		}
		prev[c] = s[i];
		next[s[i]] = c;
		s[i] = c;
	}
	cout << s << '\n';
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