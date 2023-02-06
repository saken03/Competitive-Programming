/*
	Binary Search and DSU
*/
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

class DSU {
	private:
		vector<int> parent;
		vector<int> size;
	public:
		DSU(int size) : parent(size), size(size, 1) {
			for (int i = 0; i < size; i++) {
				parent[i] = i;
			}
		}

		int get_top(int n) {
			return parent[n] == n ? n : (parent[n] = get_top(parent[n]));
		}

		bool link(int n1, int n2) {
			n1 = get_top(n1);
			n2 = get_top(n2);
			if (n1 == n2) {
				return false;
			}
			if (size[n2] > size[n1]) {
				return link(n2, n1);
			}
			parent[n2] = n1;
			size[n1] += size[n2];
			return true;
		}
};

struct Wormhole {
	int c1, c2;
	int width;
};

void solve() {  
	int cow_num, wormhole_num;
	cin >> cow_num >> wormhole_num;

	vector<int> cows(cow_num);
	for (int& c : cows) {
		cin >> c;
		c--;
	}

	int max_width = 0;
	vector<Wormhole> wormholes(wormhole_num);
	for (Wormhole& w : wormholes) {
		cin >> w.c1 >> w.c2 >> w.width;
		w.c1--;
		w.c2--;
		max_width = max(max_width, w.width);
	}

	int l = 0, r = max_width + 1;
	int valid = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;

		DSU dsu(cow_num);
		for (const Wormhole& w : wormholes) {
			if (w.width >= mid) {
				dsu.link(w.c1, w.c2);
			}
		}

		bool sortable = true;
		for (int c = 0; c < cow_num; c++) {
			if (dsu.get_top(c) != dsu.get_top(cows[c])) {
				sortable = false;
				break;
			}
		}

		if (sortable) {
			valid = mid;
			l = mid + 1;
		}
		else {
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
