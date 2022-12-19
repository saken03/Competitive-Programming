/***
PROB: dualpal
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

bool isPal(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
}

string convert_to(int b, int x) {
	string s = "";
	while (x) {
		s += x % b + '0';
		x /= b;
	}
	return s;
}

void solve() {        
	int N, s;
	cin >> N >> s;

	int n = s + 1;
	while (N) {
		int cnt = 0;
		for (int b = 2; b <= 10; b++) {
			if (isPal(convert_to(b, n))) cnt++;
		}
		if (cnt > 1) cout << n << '\n', N--;
		n++;
	}
}

int main() {
	setIO("dualpal");

	solve();

	return 0;
}   
