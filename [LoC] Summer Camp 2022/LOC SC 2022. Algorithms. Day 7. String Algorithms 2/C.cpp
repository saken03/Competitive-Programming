/***
    AUTHOR:    shabylkhan
    CREATED:   26.07.2022 15:52:06

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> p;
void kmp(string s) {
	int n = (int)s.size();
	p.resize(n);
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		p[i] = j;
	}
}

void solve() {
	string a;
	cin >> a;
	kmp(a);
	for (int i : p) cout << i << ' ';
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