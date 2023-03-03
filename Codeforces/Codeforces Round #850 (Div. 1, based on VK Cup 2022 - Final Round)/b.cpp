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

const int MAXN = 1e5;

void solve() {
	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++) 
		cin >> s[i];

	map<pair<char, char>, vector<int>> a;
	vector<tuple<int, char, int, char>> ans;

	for (int i = 0; i < n; i++) {
		map<char, int> cnt;
		for (const auto x : s[i])
			cnt[x]++;

		vector<char> need, give;
		for (const auto x : {'w', 'i', 'n'}) {
			if (cnt[x] == 0)
				need.pb(x);
			else
				for (int i = 1; i < cnt[x]; i++)
					give.pb(x);	
		}

		for (int j = 0; j < sz(need); j++) {
			char x = need[j], y = give[j];
			if (!a[{y, x}].empty()) {
				ans.emplace_back(i, y, a[{y, x}].back(), x);
				a[{y, x}].pop_back();
			}
			else 
				a[{x, y}].pb(i);
		}
	}

	char ch[3] = {'w', 'i', 'n'};
	if (a[{ch[0], ch[1]}].empty())
		swap(ch[0], ch[1]);

	for (int i = 0; i < a[{ch[0], ch[1]}].size(); i++) {
		int x = a[{ch[0], ch[1]}][i];
		int y = a[{ch[1], ch[2]}][i];
		int z = a[{ch[2], ch[0]}][i];
		ans.emplace_back(x, ch[1], y, ch[2]);
		ans.emplace_back(x, ch[2], z, ch[0]);
	}

	cout << sz(ans) << '\n';
	for (auto [a, b, c, d] : ans) 
		cout << a + 1 << " " << b << " " << c + 1 << " " << d << '\n';
}

int main() {
	setIO("");
	int tt = 1;
  cin >> tt;
	while (tt--)
		solve();
	return 0;
}