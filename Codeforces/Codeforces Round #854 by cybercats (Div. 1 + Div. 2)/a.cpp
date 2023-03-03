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
	int n, m;
	cin >> n >> m;
	
	vector<int> lost(n + 1, -1);
	unordered_set<int> s;
	int cur = n;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (s.count(x) == 0) {
			s.insert(x);
			if (cur >= 0) lost[cur] = i + 1;
			cur--;
		}  
	}

	for (int i = 1; i <= n; i++)
		cout << lost[i] << ' ';
	cout << '\n';
}

int main() {
	setIO("");
	int tt = 1;
  cin >> tt;
	while (tt--)
		solve();
	return 0;
}