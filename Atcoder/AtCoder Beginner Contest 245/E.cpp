#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) return 1;
	else if (a.first < b.first) return 0;
	else {
		if (a.second < b.second) return 1;
		else return 0;
	}
}

const int MAXN = 2 * 1e5 + 123;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < m; i++) cin >> c[i];
	for (int i = 0; i < m; i++) cin >> d[i];

	vector<pair<int, int>> e;



	for (int i = 0; i < m; i++) {
		e.emplace_back(c[i], ~i);
	}    
	for (int i = 0; i < n; i++) {
		e.emplace_back(a[i], i);
	}
	             
	sort(e.begin(), e.end(), comp);

	multiset<int> s;

	for (auto& p : e) {
		int id = p.second;
		if (id >= 0) {
			auto it = s.lower_bound(b[id]);
			if (it != s.end()) {
				s.erase(it);
			} 
			else {
				cout << "No\n";
				return 0;
			}
		} 
		else {
			id = ~id;
			s.insert(d[id]);
		}
	}
	cout << "Yes\n";
	return 0;
}