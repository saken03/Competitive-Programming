#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m), d(m);
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for (int i = 0; i < m; i++) 
		cin >> b[i];

	priority_queue<int> q;

	set<int> s;
	for (int i = 0; i < n; i++) 
		s.insert(a[i]);

	for (auto it = s.begin(); it != s.end(); it++)
		q.push(mp[*it]);

	int ans = 0;
	for (int i = 0; i < m; i++) {
	  if (q.empty()) {
	  	break;
	  }
		int x = q.top().f;
		int cur = min(b[i], x);

		ans += cur;
		b[i] -= cur;
//		cout << x << '\n';
		q.pop();
		if (x - cur > 0) 
			q.push({x - cur, tp});
	}
	cout << ans << '\n';
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
