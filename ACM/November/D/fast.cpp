#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 666;

string s;

void solve() {        
	cin >> s;        
	ll ans = 0;

	vector<int> prev(sz(s)), next(sz(s)), last(27, -1);
	for (int i = 0; i < sz(s); i++) {
		int c = s[i] - 65;
		if (last[c] == -1) last[c] = 0;
		prev[i] = last[c];
		last[c] = i + 1;
	}
	for (int i = 0; i < 27; i++) last[i] = -1;
	for (int i = sz(s) - 1; i >= 0; i--) {
		int c = s[i] - 65;
		if (last[c] == -1) last[c] = sz(s) + 1;
		next[i] = last[c];
		last[c] = i + 1;
	}

	for (int i = 0; i < sz(s); i++) {
		int r = next[i], l = prev[i];
		ans += (r - i - 1) * (i - l + 1);
		ans %= MOD;
	}
	cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	solve();
	return 0;
}