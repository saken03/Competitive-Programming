#include<bits/stdc++.h>

using namespace std;

bool comp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
	if (a.first.first < b.first.first) return 1;
	else if (a.first.first == b.first.first) {
		if (a.first.second < b.first.second) return 1;
		else return 0;
	} 
	else return 0;
}

void solve() {
	vector<pair<pair<int, int>, string>> guys;
	string name;
	int day, month;
	while (cin >> name >> day >> month) {
		guys.push_back({{month, day}, name});
	}                
	sort(guys.begin(), guys.end(), comp);

	for (auto x : guys) {
		cout << x.second << ' ';
		int day = x.first.second;
		if (day < 10) cout << 0 << day;
		else cout << day;
		cout << '.';
		int month = x.first.first;
		if (month < 10) cout << 0 << month;
		else cout << month;	
		cout << '\n';
	}
}

int main() {
	freopen("list.txt", "r", stdin);
	freopen("list_sorted.txt", "w", stdout);

	solve();

	return 0;
}