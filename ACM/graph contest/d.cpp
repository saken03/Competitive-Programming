#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 55;
const int INF = 1e9;

int n, m, k;

char c[N][N];
bool u[N][N], good;

vector<vector<pii>> cm;
vector<pii> pp;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool comp(vector<pii>& a, vector<pii>& b) {
	return sz(a) < sz(b);
}

bool corner(int x, int y) {
	if (x == 1 || x == n || y == 1 || y == m) return 0;
	return 1;
}

void dfs(int x, int y) {
	u[x][y] = 1;
	pp.pb(mp(x, y));
	if (corner(x, y)) good = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (!u[nx][ny] && c[nx][ny] == '.') {
	  	dfs(nx, ny);
		}
	}
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {                                                        
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!u[i][j] && c[i][j] == '.') {
				good = 1;
				pp.clear();
				dfs(i, j);
				if (good) {            
					cm.pb(pp);
				}
			}
		}
	}         	
	sort(cm.begin(), cm.end(), comp);
	cout << sz(cm) << '\n';
	return;
	/*
	for (int i = 0; i < sz(cm); i++) {
		for (int j = 0; j < sz(cm[i]); j++) {
			cout << cm[i][j].f << ' ' << cm[i][j].s << ' ';
		}
		cout << '\n';
	}
	return;
	*/
	int cnt = 0;
	for (int i = 1; i <= sz(cm) - k; i++) {
		cnt += sz(cm[i - 1]);
		for (auto cell : cm[i - 1]) {
			c[cell.f][cell.s] = '#';
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << c[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}