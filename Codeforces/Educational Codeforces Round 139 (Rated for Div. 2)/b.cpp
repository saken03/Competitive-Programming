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
	string s;
	cin >> n >> s;
	vector<vector<int>> v(27);
	s += '#';
	for (int i = 0; i < n; i++) v[s[i] - 'a'].pb(i); 
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < sz(v[i]); j++) {
			for (int k = j + 1; k < sz(v[i]); k++) {
				int x = v[i][j], y = v[i][k];
				if (s[x + 1] == s[y + 1] && x + 1 < y) {
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
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
