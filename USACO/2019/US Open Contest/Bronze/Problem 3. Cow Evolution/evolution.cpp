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

vector<string> all_characteristics, characteristics[30];

int n;

bool crossing(int a, int b) {
	int A = 0, B = 0, AB = 0;
	for (int i = 0; i < n; i++) {
		bool hasA = 0, hasB = 0;
		for (string s : characteristics[i]) {
			if (s == all_characteristics[a]) hasA = 1;
			if (s == all_characteristics[b]) hasB = 1;
		}
		if (hasA && hasB) AB++;
		else if (hasA) A++;
		else if (hasB) B++;
	}
	return AB && A && B;
}

void solve() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> s;
			characteristics[i].pb(s);
			bool found = 0;
			for (string k : all_characteristics) {
		  	if (s == k) {
		  		found = 1;
		  		break;
		  	}
			}
			if (!found) all_characteristics.pb(s);
		}
	}

	int N = sz(all_characteristics);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (crossing(i, j)) {
				cout << "no\n";
				return;
			}
		}
	}
	cout << "yes\n";
}

int main() {
	setIO("evolution");

	solve();

	return 0;
}