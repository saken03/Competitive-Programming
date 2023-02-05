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
	string s = "codeforces";
	char c;
	cin >> c;         
	for (int i = 0; i < sz(s); i++) 
		if (s[i] == c) {
			cout << "yes\n";
			return;
		}
	cout << "no\n";
}

int main() {
	setIO("");
	
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();

	return 0;
}   
