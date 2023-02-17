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

#define MAX 501

const int dx[] = {0, 0, -1, 1},
					dy[] = {-1, 1, 0, 0};

int n, m, mat[MAX][MAX], wp[MAX][MAX], mark[MAX][MAX], wx, wy;

void floodfill(int d) {
	queue<pair<int, int>> q;
	
	q.push(mp(wy, wx));
	mark[wy][wx] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = p.first + dy[i], nx = p.second + dx[i];
			if (ny >= 0 && ny < m && nx >= 0 && nx < n) 
				if (!mark[ny][nx] && abs(mat[p.first][p.second] - mat[ny][nx]) <= d) {
					q.push(mp(ny, nx));
					mark[ny][nx] = 1;
				}
		}
	}
	
}

bool reachable(int d) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mark[i][j] = 0;

	floodfill(d);

	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++)
			if (wp[i][j] && !mark[i][j]) 
				return false;
	return true;
}

void solve() {        
	cin >> m >> n;
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) 
			cin >> mat[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> wp[i][j];
			if (wp[i][j]) wy = i, wx = j;
		}

	int dmin = 0, dmax = 1000000000;
	while (dmin < dmax) {
		int d = (dmin + dmax) >> 1;
		if (reachable(d)) 
			dmax = d;
		else dmin = d + 1;	
	}
	cout << dmin << '\n';
}

int main() {
	setIO("ccski");

	solve();

	return 0;
}   
