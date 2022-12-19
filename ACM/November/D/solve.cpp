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
int lft[MAXN][27], rght[MAXN][27];

void solve() {        
	cin >> s;        
	ll ans = 0;
	vector<int> last(27, 0);	
	for (int i = 0; i < sz(s); i++) {
		int c = s[i] - 65;
		lft[i][c] = last[c];
		last[c] = i + 1;
	}
	for (int i = 0; i < 27; i++) last[i] = sz(s) + 1;
	for (int i = sz(s) - 1; i >= 0; i--) {
		int c = s[i] - 65;
		rght[i][c] = last[c];
		last[c] = i + 1;
	}
	for (int i = 0; i < sz(s); i++) {
		int c = s[i] - 65;
		int r = rght[i][c], l = lft[i][c];
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