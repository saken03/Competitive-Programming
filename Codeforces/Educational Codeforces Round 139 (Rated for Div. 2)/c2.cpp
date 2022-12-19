#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 2e5 + 123;

int n, a[2][MAXN];
bool bad;

void no() {
	cout << "NO\n";
	bad = 1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c; a[i][j] = (c == 'B' ? 1 : 0);
		}
	}
	for (int i = 0; i < 2; i++) {
		bool dbreak = 0;
		for (int j = 0; j < n; j++) {
			if (bad) {
				dbreak = 1;
				break;
			}
			if (i == 1 && j + 1 < n && a[i][j] == 1 && a[i - 1][j] == 1 && a[i][j + 1] == 1 && a[i - 1][j + 1] == 0) no();
			else if (i == 0 && j + 1 < n && a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 0) no();
			else if (i == 0 && j + 1 < n && a[i][j] == 1 && a[i + 1][j] == 0 && a[i][j + 1] == 0 && a[i + 1][j + 1] == 1) no();
			else if (i == 0 && j + 1 < n && a[i][j] == 0 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 0) no();
		}
		if (dbreak) break;
	}
	if (!bad) cout << "YES\n";
	bad = 0;
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
