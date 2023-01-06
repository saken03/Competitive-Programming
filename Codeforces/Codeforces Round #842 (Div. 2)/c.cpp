#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n, -1), c(n, -1);
	vector<bool> u1(n + 1), u2(n + 1);
	bool good = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (u1[a[i]] == 1) {
			if (u2[a[i]] == 1) {
				good = 0;
			}
			else {
				u2[a[i]] = 1;
				c[i] = a[i];
			}
		}
		else {
			u1[a[i]] = 1;
			b[i] = a[i];
		}
	}

	if (!good) {
		cout << "NO\n";
		return;
	}

	set<int> p, q;
	for (int i = 1; i <= n; i++) {
		p.insert(-i);
		q.insert(-i);
	}
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) p.erase(-b[i]);
		if (c[i] != -1) q.erase(-c[i]);
	}

	for (int i = 0; i < n; i++) {
		if (c[i] == -1) {
			auto x = q.lower_bound(-b[i]);
			if (x == q.end()) {
				good = 0;
				break;
			}
			c[i] = -(*x);
			q.erase(x);
		}
		if (b[i] == -1) {
		  auto x = p.lower_bound(-c[i]);
			if (x == p.end()) {
				good = 0;
				break;
			}
			b[i] = -(*x);
			p.erase(x);
		}
	}

	if (!good) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++) cout << c[i] << ' ';
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
