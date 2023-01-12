#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (s[0] == s[sz(s) - 1]) {
		cout << s.substr(0, 1) << ' ' << s.substr(1, sz(s) - 2) << ' ' << s[sz(s) - 1] << '\n';
		return;
	}
	string a = "", b = "", c = "";

	int i = 1;
	bool ok = 0;
	for (; i < sz(s) - 1; i++) {
		if (ok) b += s[i];
		if (s[i] == 'b') ok = 1;
	}   
	if (b.empty()) {
		i = 2;
		for (; i < sz(s) - 1; i++) {
			if (s[i] == 'a') {
				b = s[i];
				break;
			}
		}
	}

	for (int j = 0; j < i; j++) {
		a += s[j];
	}
	for (int j = i + 1; j < sz(s); j++) {
		c += s[j];
	}

	if ((a <= b && c <= b) || (b <= a && b <= c)) {
		cout << a << ' ' << b << ' ' << c << '\n';
	}
	else {
		cout << ":(\n";
	}
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
