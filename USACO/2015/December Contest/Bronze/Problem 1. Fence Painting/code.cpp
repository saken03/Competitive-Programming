#include<bits/stdc++.h>
using namespace std;

int main() {

	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int intersection = max(min(b, d) - max(a, c), 0);

	cout << (b - a) + (d - c) - intersection;

	return 0;
}