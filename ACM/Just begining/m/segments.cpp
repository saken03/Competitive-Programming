#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 1e5 + 123;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> l(n), r(n), x(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		s.insert(l[i]);
		s.insert(r[i]);
	}

	for (int i = 0; i < m; i++) {
		cin >> x[i];
		s.insert(x[i]);
	}

	map<int, int> comp;
	int numb = 1;
	for (auto it : s) {
		comp[it] = numb;
		numb++;
	}

	vector<int> pref(MAXN);
	for (int i = 0; i < n; i++) {
		l[i] = comp[l[i]];
		r[i] = comp[r[i]];
		if (l[i] > r[i]) swap(l[i], r[i]);
		pref[l[i]]++;
		pref[r[i] + 1]--;
	}

	for (int i = 0; i < m; i++) x[i] = comp[x[i]];

	for (int i = 1; i < numb; i++) pref[i] += pref[i - 1];

	for (int i = 0; i < m; i++) {
		cout << pref[x[i]] << ' ';
	}
}

int main() {
	setIO("segments");

	int tt = 1;
//	cin >> tt;
	while (tt--) 
		solve();
	}

	return 0;
} 
