/***
    AUTHOR:    shabylkhan
    CREATED:   29.05.2022 18:47:14
***/

#include<bits/stdc++.h>

using namespace std;
int main() {
	freopen("lostcow.in", "r", stdin);	
	freopen("lostcow.out", "w", stdout);

	int x, y;
	cin >> x >> y;

	bool turn = 1;
	int ans = 0;
	for (int p = 1; ; p += p) {
		bool db = 0;
		int xx = x;
		for (int i = 0; i < p; i++) {
			xx += (turn ? 1 : -1);
			if (xx == y) {
				db = 1;
				break;
			}
			ans++;
		}
		if (db)  break;
		turn ^= 1;
		ans += p;
	}
	cout << ans + 1;
	return 0;
} 