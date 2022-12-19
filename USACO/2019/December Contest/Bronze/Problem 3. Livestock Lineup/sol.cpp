#include<bits/stdc++.h>

using namespace std;

const vector<string> COWS = []() {
	vector<string> tmp {
		"Bessie",
		"Buttercup",
		"Belinda",
		"Bella",
		"Beatrice",
		"Blue",
		"Betsy",
		"Sue"
	};
	sort(begin(tmp), end(tmp));
	return tmp;
}();

int main() {
	map<string, int> cow_inds;
	for (int i = 0; i < (int)COWS.size(); i++) {
		cow_inds[COWS[i]] = i;
	}

	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	int req_num;
	cin >> req_num;
	vector<vector<int>> neighbors(COWS.size());
	for (int r = 0; r < req_num; r++) {
		string cow1, cow2;
		string trash;
		cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

		int c1 = cow_inds[cow1];
		int c2 = cow_inds[cow2];
		neighbors[c1].push_back(c2);
		neighbors[c2].push_back(c1);
	}

	vector<int> order;
	vector<bool> added(COWS.size());
	for (int c = 0; c < (int)COWS.size(); c++) {
		if (!added[c] && neighbors[c].size() <= 1) {
			added[c] = true;
			order.push_back(c);

			if (neighbors[c].size() == 1) {
				int prev = c;
				int at = neighbors[c][0];
				while (neighbors[at].size() == 2) {
					added[at] = true;
					order.push_back(at);

					int a = neighbors[at][0];
					int b = neighbors[at][1];
					int temp_at = a == prev ? b : a;
					prev = at;
					at = temp_at;
				}
				added[at] = true;
				order.push_back(at);
			}
		}
	}
	
	for (int c : order) {
		cout << COWS[c] << '\n';
	}
}
