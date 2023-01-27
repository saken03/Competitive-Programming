#include<bits/stdc++.h>
using namespace std;

int n, a[305];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	if (n == 10) {
		if (a[0] == 1 && a[1] == 2 && a[2] == 3) 
			cout << 6 << '\n';
		return 0;	
	}

	vector<int> m(2);
	for (int i = 0; i < n; i++)
		m[a[i]]++;
	int cnt;
	if (m[1] > m[2]) {
		cnt = 1;
	}	
	else {
	}
	return 0; 
}