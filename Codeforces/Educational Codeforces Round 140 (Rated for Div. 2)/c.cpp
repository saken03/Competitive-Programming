#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MOD = 998244353;

bool bit(int a, int b) {
	return a & (1 << b);
}

int n;
int a[105][105];

bool good(string s) {
	for (int i = 0; i < n; i++) {
		vector<int> m(2);
		for (int j = i; j < n; j++) {
			m[s[j] - '0'] = 1;
			int cnt = m[0] + m[1];
			if (a[i][j] != 0 && a[i][j] != cnt) return 0;
		}
	}
	return 1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> a[i][j];
		}
	}
	ll cnt = 0;
	for (int m = 0; m < (1 << n); m++) {
		string s = "";
		for (int i = 0; i < n; i++) {
			if (bit(m, i)) s += '1';
			else s += '0';
		}
		if (good(s)) cnt++;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
