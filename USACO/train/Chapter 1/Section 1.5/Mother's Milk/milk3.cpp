/***
PROB: milk3
LANG: C++14
username: sakenseri1
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


int A, B, C;
set<int> s;
int m[21][21][21];

void flood(int a, int b, int c) {
	if (m[a][b][c]) return;
	m[a][b][c] = 1;
	if (a == 0) 
		s.insert(c);
	int a2 = A - a;
	int b2 = B - b;
	int c2 = C - c;
	flood(a + min(a2, b), b - min(a2, b), c);
	flood(a + min(a2, c), b, c - min(a2, c));
	flood(a - min(b2, a), b + min(b2, a), c);
	flood(a, b + min(b2, c), c - min(b2, c));
	flood(a - min(c2, a), b, c + min(c2, a));
	flood(a, b - min(c2, b), c + min(c2, b));
}

void solve() {        
	cin >> A >> B >> C;
	flood(0, 0, C);
	vector<int> v;
	for (const auto i : s) 
		v.pb(i);
	for (int i = 0; i < sz(v); i++) {
		if (i == sz(v) - 1) cout << v[i];
		else cout << v[i] << ' ';
	}	
	cout << '\n';
}

int main() { 
	setIO("milk3");

	solve();

	return 0;
}   
