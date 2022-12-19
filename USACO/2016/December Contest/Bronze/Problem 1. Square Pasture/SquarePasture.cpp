/***
    AUTHOR:    shabylkhan
    CREATED:   21.05.2022 14:50:02

***/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, x4, y3, y4;
	cin >> x3 >> y3 >> x4 >> y4;
	
	int xl = min(x1, x3);
	int xr = max(x2, x4);
	int yl = min(y1, y3);
	int yr = max(y2, y4);

	cout << pow(max(xr - xl, yr - yl), 2) << '\n';
}                          

int main() {     
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);	

	int tt = 1;                
	while (tt--) {
		solve();
	}

	return 0;
} 