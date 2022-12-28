/***
PROB: 
LANG: C++14
username: sakenseri1
***/
/***
    AUTHOR:    shabylkhan
    CREATED:   19.09.2022 10:23:37

***/
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

void serve(int& h, int& m) {
	m += 20;
	if (m >= 60) m -= 60, h++;	
}

void out(int h, int m) {
	cout << h << ' ' << m << '\n';
}

void solve() {        
	int n;
	cin >> n;
	vector<pair<int, int>> in;
	for (int i = 0; i < n; i++) {
		int h, m, sabr;
		cin >> h >> m >> sabr;
		
		vector<pair<int, int>> nin;
		for (auto it : in) {
			if (!(it.f < h || (it.f == h && it.s <= m))) nin.pb(mp(it.f, it.s));
		}
		in = nin;

		if (sz(in) > sabr) {
			out(h, m);
			continue;
		}

		sort(in.begin(), in.end());
		if (sz(in)) {
			h = in[sz(in) - 1].f;
			m = in[sz(in) - 1].s;
		}
		serve(h, m);
		out(h, m);
		in.pb(mp(h, m));
	}
}


int main() {
	setIO("saloon");

	solve();

	return 0;
}   
