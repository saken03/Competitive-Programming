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
	vector<char> s(n + 1);
	vector<int> loses(n + 1), wins(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> s[i];
		if (s[i] == '0') {
			loses[i]++;
		}
		else wins[i]++;
		loses[i] += loses[i - 1];
		wins[i] += wins[i - 1];
	}
	for (int x = 2; x <= n; x++) {
		int a = loses[x - 1], b = wins[x - 1];
		int l = x - a, r = 1 + b;
		if (!a) l = 0;
		if (!b) r = x + 1;
		cout << max(l, x - r + 1) << ' ';
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
