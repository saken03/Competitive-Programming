#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;

int tr[2];

void solve() {
	string s;
	cin >> s;
	int i = 0;
	while (i < sz(s) && s[i] == '0') tr[0]++, i++;
	while (i < sz(s) && s[i] == '1') tr[1]++, i++;
	cout << a << ' ' << b;
	// -1 - case
	bool turn = 0;
	vector<int> cur(2);
	for (; i < sz(s); i++) {
		if (s[i] == turn) {
			if (cur[turn] == tr[turn]) turn ^= 1, cur[turn] = 0;

		}
		else if (s[i] == '?') {
			if (cur[turn] < tr[turn]) s[i] = turn, cur[turn]++;
				
		}
		else {
			cout << -1 << '\n';
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
} 