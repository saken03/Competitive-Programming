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
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	ll cur = 1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= cur) {
			cnt += a[i] - cur;
			cur++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	setIO("");
	int tt = 1;
  cin >> tt;
	while (tt--)
		solve();
	return 0;
}