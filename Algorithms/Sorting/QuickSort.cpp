#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int left, int right) {
	int piv = a[right];
	int i = (left - 1);
	
	for (int j = left; j <= right - 1; j++) {
		if (a[j] < piv) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);
	return (i + 1);
}

void quickSort(vector<int>& a, int left, int right) {
	if (left < right) {
		int pi = partition(a, left, right);
		quickSort(a, left, pi - 1);
		quickSort(a, pi + 1, right);
	}
}

int main() {
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quickSort(a, 0, n - 1);
	for (int i : a) cout << i << ' ';
	cout << '\n';
	return 0;
}
