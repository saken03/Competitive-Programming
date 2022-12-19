#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;

bool good(vector<vector<int>> a) {
	return (a[0][0] < a[0][1] && a[0][0] < a[1][0] && a[0][1] < a[1][1] && a[1][0] < a[1][1]);
}

vector<vector<int>> Rotate(vector<vector<int>> a) {
	vector<vector<int>> t = a;
	t[0][0] = a[1][0];
	t[0][1] = a[0][0];
	t[1][0] = a[1][1];
	t[1][1] = a[0][1];
	return t;
}

void solve() {
	vector<vector<int>> a(2, vector<int> (2));
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> a[i][j];
	for (int i = 0; i < 4; i++) {
		if (good(a)) {
			cout << "YES\n";
			return;
		}
		a = Rotate(a);
	}
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