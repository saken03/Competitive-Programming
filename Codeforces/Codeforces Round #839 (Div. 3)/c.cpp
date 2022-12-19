#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;

void solve() {
	int k, n;
	cin >> k >> n;
	int cur = 1, dif = 0;
	vector<bool> u(n + 1);
	set<int> s;
	for (int i = 1; i <= k; i++) {
		cur += dif;
		dif++;
		if (cur <= n) {
			u[cur] = 1;
			s.insert(cur);
		}
		else {
			cur = n;
			for (int K = i; K <= k; K++) {
				while (u[cur]) cur--;
				u[cur] = 1;
				s.insert(cur);
			}
			break;
		}
	}
	for (auto it : s) cout << it << ' ';
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