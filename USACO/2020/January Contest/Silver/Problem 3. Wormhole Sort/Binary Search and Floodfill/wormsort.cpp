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

void solve() {  
	int cow_num, wormhole_num;
	cin >> cow_num >> wormhole_num;

	vector<int> cows(cow_num);
	for (int& c : cows) {
		cin >> c;
		c--;
	}

	int max_width = 0;
	vector<vector<pair<int, int>>> neighbors(cow_num);
	for (int w = 0; w < wormhole_num; w++) {
		int c1, c2, width;
		cin >> c1 >> c2 >> width;
		c1--;
		c2--;
		neighbors[c1].pb({c2, width});
		neighbors[c2].pb({c1, width});
		max_width = max(max_width, width);
	}

	int l = 0, r = max_width + 1;
	int valid = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;

		vector<int> component(cow_num, -1);
		int curr_comp = 0;
		for (int c = 0; c < cow_num; c++) {
			if (component[c] != -1)
				continue;
			vector<int> frontier{c};
			while (!frontier.empty()) {
				int curr = frontier.back();
				frontier.pop_back();
				component[curr] = curr_comp;
				for (const auto& [n, w] : neighbors[curr]) {
					if (component[n] == -1 && w >= mid) 
						frontier.pb(n);
				}
			}
			curr_comp++;
		}

		bool sortable = 1;
		for (int c = 0; c < cow_num; c++) {
			if (component[c] != component[cows[c]]) {
				sortable = 0;
				break;
			}
		}

		if (sortable) {
			valid = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	
	cout << (valid == max_width + 1 ? -1 : valid) << '\n';
}

int main() {                                                                                
	setIO("wormsort");                                                                                             
	solve();
	return 0;
}   
