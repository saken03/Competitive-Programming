/***
    AUTHOR:    shabylkhan
    CREATED:   26.07.2022 16:19:14

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> p;
void kmp(string s) {
	p.resize(s.size());
	for (int i = 1; i < (int)s.size(); i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
}

void solve() {
	string a, b;
	cin >> a >> b;
	kmp(a + '#' + b);
	vector<int> v;
	for (int i = (int)a.size() + 1; i < (int)p.size(); i++) {
		if (a.size() - p[i] == 0) v.push_back(i);
		else if (a.size() - p[i] == 1) v.push_back(i - a.size() + 1);
		else if (p[i] == 0 && p[i - 1] == (int)a.size() - 1) v.push_back(i);
	}
	cout << v.size() << '\n';
	for (int i : v) cout << i << ' ';
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