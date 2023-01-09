#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.f < b.f) return 1;
	else if (a.f == b.f) {
		if (a.s > b.s) return 1;
		return 0;
	}
	return 0;
}

// think..
void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	vector<int> scores(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].f;
		a[i].s = i;
		scores[i] = i;
	}

	int score = 0;
	for (int i = 0; i < n; i++) {
		m -= a[i].f;
		if (m < 0) {
			scores[a[i].s]++;
		}
		else score++;
	}
	
	//sort(scores.begin(), scores.end());
	set<int> s;
	for (int i : scores)
		s.insert(-i);
	int place = 1;
	for (auto i : s) {
		if (score >= -i) {
			cout << place << '\n';
			return;
		}
		place++;
	}
	cout << place << '\n';
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
