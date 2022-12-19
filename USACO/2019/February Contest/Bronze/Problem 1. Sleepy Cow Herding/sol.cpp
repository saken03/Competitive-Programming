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
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	if (a + 2 == c) cout << 0;
	else if (c - b == 2 || b - a == 2) {
		cout << 1;
	}
	else cout << 2;
	cout << '\n';
	cout << max(c - b, b - a) - 1 << '\n';
}

int main() {
	setIO("herding");

	solve();

	return 0;
}