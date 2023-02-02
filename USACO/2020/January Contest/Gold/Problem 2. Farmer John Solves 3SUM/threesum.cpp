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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<int, int> table;

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
	int n, q;
	cin >> n >> q;

	vector<int> val(n);
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	vector<vector<ll>> ways(n, vector<ll>(n, 0));

	for (int i = 0; i < n; i++) {
//		unordered_map<int, int> frq;
		gp_hash_table<int,int> g({},{},{},{},{1<<13}); 

		for (int j = i + 1; j < n; j++) {
			int comp = -val[i] - val[j];
			ways[i][j] = frq[comp];
			frq[val[j]]++;
		}
	}	

	for (int i = n - 1; i >= 0; i--) 
		for (int j = i + 1; j < n; j++) 
			ways[i][j] += ways[i + 1][j] + ways[i][j - 1] - ways[i + 1][j - 1];
	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << ways[l - 1][r - 1] << '\n';
	}
}

int main() {
	setIO("threesum");

	solve();

	return 0;
}   
