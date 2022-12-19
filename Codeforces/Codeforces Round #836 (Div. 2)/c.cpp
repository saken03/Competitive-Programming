#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	map<int, bool> used;
	a[1] = x;
	a[n] = 1;
	used[1] = used[x] = 1; 
	for (int i = 2; i < x; i++) {
		int u = i;
		while (used[u]) u += i;
		a[i] = u;
		if (u > n) {
			cout << -1 << '\n';
			return;
		}
		used[u] = 1;
	}
	int u = x;
	while (used[u]) u += x;
	a[x] = u;
	if (u > n) {
			cout << -1 << '\n';
			return;
	}
	used[u] = 1;
	for (int i = x + 1; i < n; x++) {
		int u = i;
		while (used[u]) u += i;
		a[i] = u;
		if (u > n) {
			cout << -1 << '\n';
			return;
		}
		used[u] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] % i != 0) {
			cout << -1 << '\n';
			return;
		} 
	}
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << '\n';
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
