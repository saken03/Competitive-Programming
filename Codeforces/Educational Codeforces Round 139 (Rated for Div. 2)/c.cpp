#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 2e5 + 123;

int n;
int a[2][MAXN], k, cnt;
bool was[2][MAXN], good = 1;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool appr(int x, int y) {
	if (x >= 0 && x < 2 && y >= 0 && y < n) return 1;
	return 0;
}

void dfs(int x, int y) {
	was[x][y] = 1;
	k++;
	int cur = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (appr(nx, ny) && !was[nx][ny] && a[nx][ny] == 1) {
			dfs(nx, ny);
			cur++;
		}
	}
	if (cur > 1) {
		good = 0;
		return;
	}
}

void solve() {
	cin >> n;
	cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c; a[i][j] = (c == 'B' ? 1 : 0);
			cnt += a[i][j];
		}
	}
	
	if (a[0][0] == 1) dfs(0, 0);
	if (k == cnt && good) {
		cout << "YES\n";
		return;
	}
	good = 1;
	for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) was[i][j] = 0;
	k = 0;
	
	
	if (a[1][0] == 1) dfs(1, 0);
	if (k == cnt && good) {
		cout << "YES\n";
		return;
	}
	good = 1;
	for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) was[i][j] = 0;
	k = 0;
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
} 
