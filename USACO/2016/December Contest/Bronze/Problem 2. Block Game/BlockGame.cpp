/***
    AUTHOR:    shabylkhan
    CREATED:   27.05.2022 18:21:49

***/

#include<bits/stdc++.h>

using namespace std;

const int ALP = 26;

void count(const string &s, vector<int> &freq) {
	for (char c : s) {
		freq[c - 'a']++;
	}
}

int main() {
  freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> ans(ALP);
	while (n--) {
		string a, b;
		cin >> a >> b;
		vector<int> freq1(ALP), freq2(ALP);
		count(a, freq1);
		count(b, freq2);
		for (int i = 0; i < ALP; i++) {
			ans[i] += max(freq1[i], freq2[i]);
		}
	}
	for (int i : ans) {
		cout << i << '\n';
	}

	return 0;
} 