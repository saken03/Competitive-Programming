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

const int MAXA = (int)1e10;
const int N = 500;

int n, m;
int g[N][N];
bool vis[N][N];
vector<pair<int, int>> waypoints;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void clear() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			vis[i][j] = false;
}

void floodfill(int x, int y, int D) {	
	clear();
	queue<pair<int, int>> bfs;
	bfs.push({x, y});
	vis[x][y] = 1;

	while (!bfs.empty()) {
		const auto cur = bfs.front();
		vis[cur.f][cur.s] = 1;

		for (int d = 0; d < 4; d++) {
			int nx = cur.f + dx[d];
			int ny = cur.s + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || 
				abs(g[cur.f][cur.s] - g[nx][ny]) > D) continue;
			// bfs.push({nx, ny});
		}
	}
}

bool check(int x) {
	floodfill(waypoints[0].f, waypoints[0].s, x);

	for (const auto wp : waypoints) 
		if (!vis[wp.f][wp.s])
			return false;
	return true;
}

void solve() {        
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> g[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			bool wp;
			cin >> wp;
			if (wp) waypoints.pb({i, j});
		}

	cout << check(50);

	// int l = 0, r = MAXA, D = MAXA;
	// while (l <= r) {
	// 	int mid = (l + r) >> 1;
	// 	if (check(mid)) {
	// 		r = mid - 1;
	// 		D = mid;
	// 	}
	// 	else 
	// 		l = mid + 1;
	// }

	// cout << D << '\n';
}

int main() {
	setIO("ccski");

	solve();

	return 0;
}   
