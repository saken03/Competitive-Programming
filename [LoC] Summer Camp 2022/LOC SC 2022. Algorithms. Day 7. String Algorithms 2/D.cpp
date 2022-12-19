/***
    AUTHOR:    shabylkhan
    CREATED:   26.07.2022 15:59:17

***/

#include<bits/stdc++.h>

using namespace std;
       
vector<int> p;
void kmp(string s) {
	int n = (int)s.size();
	p.resize(n);
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
}

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	kmp(s);       
	int len = n - p[n - 1];
	if (n % len == 0) cout << len;
	else cout << n;
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