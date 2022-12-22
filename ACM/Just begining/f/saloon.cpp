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
		while (!st.empty() && st.top().f <= h && st.top.s < m) st.pop();
		if (i != 0) {
			if (st.top().f == h && st.top.s == m) {
				st.pop();
				serve(h, m);
				st.push(mp(h, m));
				out(h, m);
			}  
			else if (sz(st) > sabr) {
				out(h, m);
			}
			continue;
		}
		serve(h, m);               
		st.push(mp(h, m));
		out(h, m);
	}
}


int main() {
	setIO("saloon");

	solve();

	return 0;
}   
