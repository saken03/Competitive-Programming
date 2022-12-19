/***
PROB: transform
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

void answer(int x) {
	cout << x << '\n';
	exit(0);
}

int n;                

bool equal(vector<string> a, vector<string> b) {
	for (int i = 0; i < n; i++) {
		string s1 = "", s2 = "";
		for (int j = 0; j < n; j++) {
			s1 += a[i][j];
			s2 += b[i][j];
		}
		if (s1 != s2) return 0;
	}
	return 1;
}

vector<string> mirror(vector<string> a) {
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; j < n; j++) s += a[i][j];
		reverse(s.begin(), s.end());
		for (int j = n - 1; j >= 0; j--) a[i][j] = s[j];
	}
	return a;
}

vector<string> trans_1(vector<string> a) {
	vector<string> b = a, v;
	for (int i = 0; i < n; i++) {
		v.pb(a[i]);
	}
	reverse(v.begin(), v.end());
	for (int j = n - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			a[i][j] = v[j][i];
		}
	}
	return a;
}

vector<string> trans_2(vector<string> a) {
	vector<string> b = a, v;
	for (int i = 0; i < n; i++) {
		v.pb(a[i]);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		reverse(v[i].begin(), v[i].end());
		for (int j = 0; j < n; j++) {
			a[i][j] = v[i][j];
		}
	}
	return a;
}

vector<string> trans_3(vector<string> a) {
	vector<string> b = a, v;
	for (int i = 0; i < n; i++) {
		v.pb(a[i]);
	}
	for (int j = 0; j < n; j++) {
		reverse(v[j].begin(), v[j].end());
		for (int i = 0; i < n; i++) {
			a[i][j] = v[j][i];
		}
	}
	return a;
}

void solve() {                                        
	cin >> n;
	vector<string> s(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}   
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	if (equal(trans_1(s), t)) answer(1);
	if (equal(trans_2(s), t)) answer(2);
	if (equal(trans_3(s), t)) answer(3);
	if (equal(mirror(s), t)) answer(4);
	s = mirror(s);
	if (equal(trans_1(s), t) || equal(trans_2(s), t) || equal(trans_3(s), t)) answer(5);
	if (equal(s, t)) answer(6);
	answer(7);
}

int main() {
	setIO("transform");

	solve();

	return 0;
}   
