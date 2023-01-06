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

void solve() {        
	int n, t;
	cin >> n >> t;             
	vector<ll> x(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> s[i];
		x[i] += s[i] * t;
	}

	// minimum number of lis is maximum size of longest non-increasing subsequence
	// longest non-increasing subs is equivalent to longest increasing subs( or lis) of reverse of the array
	reverse(x.begin(), x.end());
	vector<ll> lns;
	for (int i = 0; i < n; i++) {
		int p = upper_bound(begin(lns), end(lns), x[i]) - begin(lns);
		if (p == sz(lns)) 
			lns.pb(x[i]);
		else
			lns[p] = x[i];	
	}
	cout << sz(lns) << '\n';
}

int main() {
	setIO("cowjog");

	solve();

	return 0;
}   
