#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int INF = (int)1e6;
const int N = 1005;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;
int ans = INF;

char g[N][N];
bool vis[N][N];

pair<int, int> up[N][N], dwn[N][N], lft[N][N], rght[N][N];

bool good(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')  // can add vis to here
		return 0;
	return 1;	
}

void rec(int x, int y, int cur = 0, int portals_used = 0, int direction = -1) {
// 	cout << "Reached: " << x << ' ' << y << '\n';	
	if (!good(x, y)) 
		return;

	if (g[x][y] == 'C') {
		ans = min(ans, cur);
		return;
	}                                               

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		if (!good(nx, ny) || vis[nx][ny]) 
			continue;

		vis[nx][ny] = 1;
		rec(nx, ny, cur + 1, portals_used, d);
		vis[nx][ny] = 0;

		if (d != direction && portals_used < 2) {
			while (good(nx, ny) && g[nx][ny] != '#') {
				nx += dx[d];
				ny += dy[d];
			} 
			nx -= dx[d];
			ny -= dy[d];
    
      if ((nx == x && ny == y) || vis[nx][ny]) {
      	continue;             
      }

     	vis[nx][ny] = 1;
		 	rec(nx, ny, cur + 1, portals_used + 1, -1);
		 	vis[nx][ny] = 0;
		}  
	}
}
/*
void pre_calc() {
	int x = -1, y = -1;
	bool found = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (found) 
				if (g[i][j] != '#') 
					lft[i][j] = {x, y};
			else
				if (g[i][j] != '#') {
					found = 1;
					x = i;
					y = j;
				}
		}

	x = -1, y = -1;
	found = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (found)
				if (g[i][j] != '#')
					up[i][j] = {x, y};
		}
	}
} 
*/

void solve() {
	cin >> n >> m;
	
	int sx = -1, sy = -1;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}

//	pre_calc();
	rec(sx, sy);	
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
} 
