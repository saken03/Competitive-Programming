#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;

bool good(string a, string b) {
	for (int i = 0; i < sz(a); i++) {
		if (a[i] == b[i] || a[i] == '?') continue;
	}
	return 1;
}

void solve() {
	string s;
	cin >> s;
/*
	cout << good(s, "01");
	return;
*/
	int mx = 0;
	string ans = "";
	for (int a = 1; a <= sz(s); a++) {
		for (int b = 0; b <= sz(s); b++) {
			string w = "", bl = "";
			for (int i = 0; i < a; i++) w += '0';
			for (int i = 0; i < b; i++) bl += '1';

			string t = "";
			int turn = 0;
			while (sz(t) < sz(s)) {
				if (!turn) t += w;
				else t += bl;
				turn ^= 1;
			}

			t = t.substr(0, (int)s.size());
			if (good(s, t) && mx <= b) {
				mx = b;
				ans = t;
			}
		}
	}
	if (ans == "") {
		cout << -1 << '\n';
		return;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 