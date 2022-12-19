#include<bits/stdc++.h>

using namespace std;

int minimumSwaps(string s) {
	stack<char> st;
	int operations = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '(') {
			st.push('(');
		}
		else {
			if (!st.empty() && st.top() == '(') st.pop();
			else operations++;
		}
	}
	return operations;
}
  
int main() {
	string s;
	cin >> s;
	cout << minimumSwaps(s) << '\n';	

	return 0;
}