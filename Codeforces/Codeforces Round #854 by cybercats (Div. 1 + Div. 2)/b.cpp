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
	int n;
	cin >> n;
	
	int mn = (int)1e10, pos = 0;
	vector<int> a(n);
	bool one = 0, none = 0;
	for (int i = 0; i < n; i++) { 
		cin >> a[i];
		if (a[i] < mn) {
			mn = a[i];
			pos = i;
		}
		if (a[i] == 1) one = 1;
		else none = 1;
	}	
	
	if (one && none) {
		cout << -1 << '\n';
		return;
	}

	vector<pair<int, int>> operations;
	for (int i = 0; i < n; i++) {
		if (a[pos] == a[i]) continue;
		while (a[i] > a[pos]) {
			operations.pb({i, pos});
			if (a[i] % a[pos] != 0) {
				a[i] /= a[pos];
				a[i]++;  
			}
			else 
				a[i] /= a[pos];
		}
		if (a[i] < a[pos]) {
			pos = i;
			i = -1;
		}
	}  
	
	unordered_map<int, bool> m;
	for (int i = 0; i < n; i++) {
		m[a[i]] = 1;
	}
	if (sz(m) > 1) {
		cout << -1 << '\n';
	}
	else {
		cout << sz(operations) << '\n';
		if (sz(operations) == 0) return;
		for (const auto it : operations) {
			cout << it.f + 1 << ' ' << it.s + 1 << '\n';	
		}
	} 
}

int main() {
	setIO("");
	int tt = 1;
  cin >> tt;
	while (tt--)
		solve();
	return 0;
}