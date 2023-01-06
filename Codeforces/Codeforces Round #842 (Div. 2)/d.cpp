#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), pos(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 	
		pos[a[i]] = i;
		if (a[i] != pos[a[i]]) cnt++;
	}
	cout << abs(cnt - 2) << '\n';
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
