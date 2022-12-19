/***
    AUTHOR:    shabylkhan
    CREATED:   26.07.2022 15:37:12

***/

#include<bits/stdc++.h>

using namespace std;

vector<int> z;
void kmp(string s) {
	int n = (int)s.size();
	z.resize(n);
	for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

void solve() {
	string s;
	cin >> s;
	kmp(s);
	reverse(z.begin(), z.end());
	z.pop_back();
  reverse(z.begin(), z.end());
	for (int i : z) cout << i << ' ';	
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