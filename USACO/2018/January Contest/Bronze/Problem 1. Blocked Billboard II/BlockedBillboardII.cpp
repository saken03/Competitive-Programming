/***
    AUTHOR:    shabylkhan
    CREATED:   17.05.2022 16:59:10
***/

#include<bits/stdc++.h>

using namespace std;

bool covered(int x1, int y1, int x3, int y3, int x4, int y4) {
	return x1 >= x3 && x1 <= x4 && y1 >= y3 && y1 <= y4;
}

void solve() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	int corner_num = 0;                               
	if (covered(x1, y1, x3, y3, x4, y4)) corner_num++;
	if (covered(x1, y2, x3, y3, x4, y4)) corner_num++;
	if (covered(x2, y1, x3, y3, x4, y4)) corner_num++;
	if (covered(x2, y2, x3, y3, x4, y4)) corner_num++;

	if (corner_num == 4) {
		cout << 0 << '\n';
		return;
	} else if (corner_num < 2) {
		cout << (x2 - x1) * (y2 - y1) << '\n';
	} else {
		int xl = max(x1, x3);
		int xr = min(x2, x4);
		int yl = max(y1, y3);
		int yr = min(y2, y4);
		cout << (x2 - x1) * (y2 - y1) - (xr - xl) * (yr - yl) << '\n';
	}
}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	solve();

	return 0;
} 