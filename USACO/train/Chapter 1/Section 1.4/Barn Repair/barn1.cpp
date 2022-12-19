/***
PROB: barn1
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

void solve() {                                              
	int m, n, s;
	cin >> m >> n >> s; vector<int> b(s), d(s);
	for (int i = 0; i < s; i++) {
		cin >> b[i];
	}
	if (m >= s) {
		cout << s << '\n';
		return;
	}
	sort(b.begin(), b.end());
/*
	for (int i = 0; i < s; i++) cout << b[i] << ' '; 
	cout << '\n';
	for (int i = 0; i < s; i++) cout << d[i] - 1 << ' ';
	return;
*/
	for (int i = 1; i < s; i++) d[i] = b[i] - b[i - 1];          
	sort(d.rbegin(), d.rend());
	n = b[s - 1];
	n -= b[0] - 1;
	for (int i = 0; i < m - 1; i++) {
		n -= d[i] - 1;
	}
	cout << n << '\n';
}

int main() {
	setIO("barn1");

	solve();

	return 0;
}   
