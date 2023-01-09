#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n;
vector<int> a[51];
int mx;

int beauty(vector<int> a[]) {
  vector<int> u(n * n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx > 1 || nx > n || ny < 1 || ny > n) continue;
				u[abs(a[nx][ny] - a[i][j])] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n * n; i++) cnt += u[i];
	return cnt;
}

void rec(int x, int y) {
	if (x > n || y > n) {
		mx = max(mx, beauty(a));
		return;
	}
	vector<int> u(n * n + 1);
	for (int i = 1; i <= n * n; i++) {
		if (!u[i]) {
			u[i] = 1;
			a[x][y] = i;
			y++;
			if (y > n) y = 1, x++;
			rec(x, y);
			y--;
			if (y < 1) y = n, x--;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i].resize(n + 1);
	rec(1, 1);
	cout << mx;
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
