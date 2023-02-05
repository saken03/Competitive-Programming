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

	int ans = n;
	int i = 0, j = n - 1;
	while (1) {
		char a = s[i], b = s[j];
		if (a == b) break;
		ans -= 2;
		i++;
		j--;	
	}
	cout << max(0, ans) << '\n';
}

int main() {                                                                                
	setIO("");                                                                                             
	
	int tt = 1;
	cin >> tt;
	while (tt--) 
		solve();

	return 0;
}   
