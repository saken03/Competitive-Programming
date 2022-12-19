#include<bits/stdc++.h>
using namespace std;

int cost(string s) {
		int n = (int)s.size();
	int zeros = 0, ones = 0;

	for (int i = 0; i < n; i++) {  
		if (s[i] == '0') zeros++;
	}
	
	int mn = max(zeros, ones);
	int last = 0, i = 0;

	for (; i < n; i++) {
		if (s[i] == '1') {
			if (mn >= max(zeros, ones + 1)) {
				mn = max(zeros, ones + 1);
				ones++;
				last++;
			}
			else break;
		}   
		else {
			if (mn > max(zeros - 1, ones)) {
				mn = max(zeros - 1, ones);
				zeros--;
				last = 0;
			}
		}
	}

	ones -= last;
	int j = i;
	
	for (i = n - 1; i > j; i--) {
		if (s[i] == '1') {
			if (mn >= max(zeros, ones + 1)) {
				mn = max(zeros, ones + 1);
				ones++;
			}
			else break;
		}
		else {   
			if (mn > max(zeros - 1, ones)) {
				mn = max(zeros - 1, ones);
				zeros--;
		 	}
		}
	}
	return mn;
}

void solve() {
	string s;
	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	
	cout << min(cost(s), cost(t)) << '\n';

/*	if (cost(s) < cost(t)) {
		2
	}*/
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