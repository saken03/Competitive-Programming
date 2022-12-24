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
	if (m > 60) m -= 60, h++;	
}

void out(int h, int m) {
	cout << h << ' ' << m << '\n';
}

void solve() {        
	int n;
	cin >> n;
	stack<pair<int, int>> in;
	for (int i = 0; i < n; i++) {
		int h, m, sabr;
		cin >> h >> m >> sabr;
		while (!in.empty() && (in.top().f < h || (in.top().f == h && in.top().s <= m))) in.pop();
		if (!in.empty()) {
			if (sz(in) > sabr) {
				out(h, m);
				continue;
			}
			h = in.top().f;
			m = in.top().s;
		}
		serve(h, m);

		if (in.empty()) {
			out(h, m);
			in.push(mp(h, m));
		}
		else {
			out(h, m);
			in.push(mp(h, m));
		}
	}
}


int main() {
	setIO("saloon");

	solve();

	return 0;
}   
