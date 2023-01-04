#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), m(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (a[i] == b[i]) m[a[i]]++;
		else m[a[i]]++, m[b[i]]++;
	}
	ll ans = 1;
	bool bug = 0;
	vector<bool> u(n + 1);
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			ans *= 3;
			ans %= MOD;
			u[a[i]] = 1;
			m[a[i]]--;
			continue;
		}
		int x = m[a[i]], y = m[b[i]];
		if (x > 1 && y > 1) {
			if (!u[a[i]] && !u[b[i]]) {
				ans *= 2;     		
				ans %= MOD;
			}
			if (!u[a[i]]) {
				m[a[i]]--;
				u[a[i]] = 1;
			}
			else {
				m[b[i]]--;
				u[b[i]] = 1;
			}
		}
		else {
			if (!u[a[i]]) {
				u[a[i]] = 1;
				m[a[i]]--;
			}
			else {
				u[b[i]] = 1;
				m[b[i]]--;
			}	
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!u[i]) {
			bug = 1;
			break;
		}
	}
	cout << (bug ? 0 : ans) << '\n';
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
