#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	int x;
	cin >> x;
	
	int ans;
	
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		
		if (a[mid] < x) {
			l = mid + 1;
		}
		else if (a[mid] > x) {
			r = mid - 1;
			ans = mid;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
