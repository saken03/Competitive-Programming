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

vector<vector<bool>> connected;
vector<bool> visited;

int reachable_cows(int c) {
	visited[c] = 1;
	int reached = 1;
	for (int nc = 0; nc < sz(connected); nc++) {
		if (!visited[nc] && connected[c][nc]) {
			visited[nc] = 1;
			reached += reachable_cows(nc);
		}
	}
	return reached;
}

void solve() {        
	int cow_num;
	cin >> cow_num;
	vector<int> x(cow_num), y(cow_num);
	vector<int> power(cow_num);
	for (int c = 0; c < cow_num; c++) {
		cin >> x[c] >> y[c] >> power[c];
	}

	connected = vector<vector<bool>>(cow_num, vector<bool>(cow_num));
	for (int i = 0; i < cow_num; i++) {
		for (int j = 0; j < cow_num; j++) {
			int dist_squared = (
				(x[i] - x[j]) * (x[i] - x[j])
				+ (y[i] - y[j]) * (y[i] - y[j])
			);
			connected[i][j] = dist_squared <= power[i] * power[i];
		}
	}

	int max_cows = 0;
	for (int c = 0; c < cow_num; c++) {
		visited.assign(cow_num, 0);
		max_cows = max(max_cows, reachable_cows(c));
	}

	cout << max_cows << '\n';
}

int main() {
	setIO("moocast");

	solve();

	return 0;
}   
