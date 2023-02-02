#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int INF = (int)1e10;

void solve() {
	int n;
	cin >> n;
	if (__builtin_popcount(n) == 1) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}






