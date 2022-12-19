/***
PROB: palsquare
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

string convert_to(int b, int x) {
	string s = "";
	while (x) {
		int a = x % b;
		if (a > 9) {
			s += 'A' + (a - 10);
		}
		else s += '0' + a;
		x /= b;
	}
	reverse(s.begin(), s.end());
	return s;
}

void solve() {        
	int b;
	cin >> b;
	for (int i = 1; i <= 300; i++) {
		string n = convert_to(b, i * i);
		string t = n; reverse(n.begin(), n.end());
		if (n == t) cout << convert_to(b, i) <<  ' ' << n << '\n';
	}
}

int main() {
	setIO("palsquare");

	solve();

	return 0;
}   
