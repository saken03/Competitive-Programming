/***
PROB: 
LANG: C++14
username: sakenseri1
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

const int N = 105;

int n;

void solve() {        
	cin >> n;

	vector<int> a(n), id(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++) 
		cin >> id[i];

	for (int t = 0; t < 3; t++) {
		vector<int> nw(n);
		for (int i = 0; i < n; i++) {
			nw[i] = id[a[i]];
		}
		id = nw;
	}

	for (int i = 0; i < n; i++) 
		cout << id[i] << '\n';
}

int main() {
	setIO("shuffle");

	solve();

	return 0;
}   
