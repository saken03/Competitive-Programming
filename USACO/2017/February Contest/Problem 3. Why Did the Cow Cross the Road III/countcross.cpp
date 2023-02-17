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

const int K = 105;

int n, k, r;
vector<pair<int, int>> cow(K);
vector<bool> cross_roads(K);
map<pair<int, int>, pair<int, int>> roads;

void floodfill(int c, bool crossed = 0) {
	visited[c] = 1;
	int x = cow[c].f, y = cow[c].s;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (!good(nx, ny)) 
		if (!visited[nx][ny]) {
		}
	}
}

void solve() {        
	cin >> n >> k >> r;

	for (int i = 0; i < r; i++) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;

		roads[{i1, j1}][{i2, j2}] = 
		roads[{i2, j2}][{i1, j2}] = 1;
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		cow[i] = {a, b};
	}

	// bruteforce
	int ans = 0;
	for (int a = 1; a <= k; a++) {
		floodfill(a);
		bool distant = 0;
		
		for (int b = a + 1; b <= k; b++) 
			if (cross_roads[b]) {
				distant = 1;
				break;
			}

		ans += distant;
	}

	cout << ans << '\n';
}

int main() {
	setIO("countcross");

	solve();

	return 0;
}   
