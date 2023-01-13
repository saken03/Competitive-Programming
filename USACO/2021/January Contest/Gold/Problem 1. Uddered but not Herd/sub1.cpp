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
	string heard; cin >> heard;
	int n = 0;
	map<char, int> index;
	for (char letter: heard) if (!index.count(letter)) index[letter] = n++;
	vector<vector<int>> adjacent(n, vector<int> (n));
	for (int j = 1; j < sz(heard); j++) 
		adjacent[index[heard[j - 1]]][index[heard[j]]]++;  
	vector<int> p(n); iota(begin(p), end(p), 0);
	int ans = INT_MAX;
	do {
		int cur_ans = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)                                    
				cur_ans += adjacent[p[i]][p[j]];
		// now cur_ans = evaluate(p)
		ans = min(ans, cur_ans);	
	} while (next_permutation(begin(p), end(p)));
	cout << ans << '\n';	
}

int main() {
	setIO("");

	solve();

	return 0;
}   
