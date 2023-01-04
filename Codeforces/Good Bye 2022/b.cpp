#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	map<int, bool> m;
	int a = n, b = 1;
	while (sz(m) < n) {
		for (int i = 1; i < k; i++) {
			m[a] = 1;
			cout << a-- << ' ';
			if (sz(m) == n) {
				cout << '\n';
				return;
			}
		}
		m[b] = 1;
		cout << b++ << ' ';
	}
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
