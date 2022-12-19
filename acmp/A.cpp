#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	map<char, bool> vow;
	vow['a'] = vow['o'] = vow['y'] = vow['e'] = vow['u'] = vow['i'] = 1;
	string t = "";
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
	}	

	for (int i = 0; i < (int)s.size(); i++) {
		if (vow[s[i]]) continue;
		t += '.';
		t += s[i];
	}
	cout << t << '\n';
}

int main() {
	ios::sync_with_stdio(0);   
	cin.tie(0);
	
	solve();

	return 0;
} 