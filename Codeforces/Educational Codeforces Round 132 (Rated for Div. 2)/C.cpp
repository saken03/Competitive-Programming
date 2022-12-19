/***
    AUTHOR:    shabylkhan
    CREATED:   21.07.2022 21:07:40

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s, t = "";
	cin >> s;
	if (s == "??") {
		cout << "YES\n";
		return;
	}
	int cnt = 0;
	for (char c : s) if (c == '?') cnt++;
	if (s[0] == '?') cnt--;
	if (s[s.size() - 1] == '?') cnt--;
	cout << (cnt > 1 ? "NO" : "YES") << '\n';
/*	
	vector<char> st;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (c == '(') {
			st.push_back('(');
		}
		else if (c == ')') {
			if ((int)st.size() != 0 && st[st.size() - 1] == '(') st.pop_back();
			else st.push_back(')');
		}
		else {     
			for (int j = (int)st.size() - 1; j >= 0; j--) {
				t += st[j];
			}            
			t += '?';
			st.clear();
		}
	}
	for (int j = (int)st.size() - 1; j >= 0; j--) {
				t += st[j];
	}
	cout << t << '\n'; */
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