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
	int cur = 0;
	if (s[0] == '1') cur = 1;
	for (int i = 1; i < n; i++) {
		char c = s[i];
		if (c == '0') {
			cout << '+';
		}
		else {
			if (cur) cout << '-', cur--;
			else cout << '+', cur++;
		}
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
