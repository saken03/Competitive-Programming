/***
PROB: 
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

int a[250];

void rec(int l, int r) {
	if (l == r) {
		return a[l];
	}
	int al = a[l];
	int x = rec(l + 1, r);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cout << rec(0, n - 1) << '\n';	
}

int main() {
	setIO("248");

	solve();

	return 0;
}   
