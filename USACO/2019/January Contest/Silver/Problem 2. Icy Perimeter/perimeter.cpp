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

const int MAXN = 1005;
const int INF = 50000;

int n;
int maxArea, minPerimeter, curArea, curPerimeter;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
bool vis[MAXN][MAXN];
char g[MAXN][MAXN];


void floodfill(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || g[x][y] == '.') {
		curPerimeter++;
		return;
	}

	vis[x][y] = 1;
	curArea++;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (!vis[nx][ny]) 
			floodfill(nx, ny);
	}
}

void solve() {        
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (g[i][j] == '#' && !vis[i][j]) {
				curArea = 0;
				curPerimeter = 0;
				floodfill(i, j);
				if (maxArea < curArea) {
					maxArea = curArea;
					minPerimeter = curPerimeter;
				}
				else if (maxArea == curArea)
					minPerimeter = min(minPerimeter, curPerimeter);
			}
	
	cout << maxArea << ' ' << minPerimeter << '\n';
}

int main() {
	setIO("perimeter");

	solve();

	return 0;
}   
