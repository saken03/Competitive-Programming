#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

void solve() {
	string s;
	cin >> s;
	cout << s;
	reverse(s.begin(), s.end());
	cout << s << '\n';	
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
