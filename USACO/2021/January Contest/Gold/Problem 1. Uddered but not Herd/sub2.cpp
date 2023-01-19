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

void solve() {        
	string heard;
	cin >> heard;
	map<char, int> index;
	int n = 0;
	for (char letter : heard) 
		if (!index.count(letter))
			index[letter] = n++;

	vector<vector<int>> adjacent(n, vector<int> (n));
	for (int j = 1; j < sz(heard); j++) 
		adjacent[index[heard[j - 1]]][index[heard[j]]]++;

	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int msk = 1; msk < (1 << n); msk++) {
		dp[msk] = sz(heard);
		for (int j = 0; j < n; j++) {
			if (msk & (1 << j)) {
				int sum = dp[msk ^ (1 << j)];
				for (int k = 0; k < n; k++) 
					if (msk & (1 << k))
						sum += adjacent[j][k];
				dp[msk] = min(dp[msk], sum);
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
} 

int main() {
	setIO("");

	solve();

	return 0;
}   
