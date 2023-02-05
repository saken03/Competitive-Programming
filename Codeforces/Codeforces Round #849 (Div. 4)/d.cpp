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

void solve() {        
	int n;
	string s;
	cin >> n >> s;
	
	unordered_set<char> m;
	vector<int> pref(n), suff(n);
	for (int i = 0; i < n; i++) {
		m.insert(s[i]);
		pref[i] = sz(m);
	}
	m.clear();
	for (int i = n - 1; i >= 0; i--) {
		m.insert(s[i]);
		suff[i] = sz(m);
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, pref[i] + suff[i + 1]);
	}
	cout << ans << '\n';
}

int main() {                                                                                
	setIO("");                                                                                             
	
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();

	return 0;
}   
