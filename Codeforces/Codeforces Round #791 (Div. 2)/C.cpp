#include<bits/stdc++.h>
using namespace std;

bool good(pair<int, int> ruk, int x, int y, int y1, int x1) {
	if ((ruk.first <= x && ruk.first >= x1) || (ruk.second <= y && ruk.second >= y1)) {
		return 1;
	}
	return 0;		
}

void solve() {
	int n, q;
	cin >> n >> q;
	
	set<pair<int, int>> rook;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			rook.insert({x, y});
		}
		else if (t == 2) {
			int x, y;
			cin >> x >> y;
			rook.erase(rook.find({x, y}));
		}
		else {
			int x2, y2, x1, y1;
			cin >> x1 >> y1 >> x2 >> y2;
			
			auto rk = rook.lower_bound({x1, y1});
			pair<int, int> ruk = *rk;
			bool ok = 0;
			for (int j = 0; j < 50; j++) {
				if (j != 0) rk++;
				if (rk == rook.end()) break;
				ruk = *rk;
				if (good(ruk, x2, y2, y1, x1)) {
					cout << "Yes\n";
					ok = 1;
					break;
				}	
			}
			if (!ok) cout << "No\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
}