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

/*--------------------------------------------------------------*/

map<string, string> g;

void solve() {
	int n;
	string AA, BB;
	cin >> AA >> BB;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		g[b] = a;
	}
	map<string, bool> visited;
	map<string, int> depth;
	string aa = AA, bb = BB;
	int lvl = 0;
	while (1) {
		visited[aa] = 1;
		if (g[aa] != NULL) break;
		aa = g[aa];
		depth[aa] = ++lvl;
	}
	string ancestor = "";
	lvl = 0;
	while (1) {
		if (visited[bb]) {
			ancestor = bb;
			break;
		}
		if (g[bb] != NULL) break;
		bb = g[bb];
		lvl++;
	}
	string ans = "";
	if (depth[ancestor] > lvl) {
		ans = bb + " is the ";
		if (depth[ancestor] == 1 && lvl == 1) {
			ans = "SIBLINGS";
		}
		gg
	}
	else {
		string ans = aa + " is the ";
		if (depth[ancestor] == 1 && lvl == 1) {
			ans = "SIBLINGS";
		}
	}
}

int main() {
	setIO("family");

	solve();

	return 0;
}