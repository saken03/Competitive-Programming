/***                
PROB: pprime
LANG: C++14
username: sakenseri1
***/
#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end() 
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
typedef long long ll;
 
using namespace std;

void setIO(string name = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int a, b; 

void input() {
	cin >> a >> b;
}

bool isPrime(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) 
			return 0;
	} 
	return 1;
}

vector<int> palindromes;

bool isPalindrome(int n) {
	string s = "";
	while (n) {
		int t = n % 10;
		s += t + '0';
		n /= 10;
	}
	string rev_s = s;
	reverse(all(rev_s));
	return s == rev_s;
}

void find_palindromes() {
	for (int i = a; i <= b; i++) 
		if (isPalindrome(i))
			palindromes.pb(i);
}

void solve() {
	find_palindromes();
}

void output() {
	for (const int i : palindromes) {
		if (isPrime(i)) {
			cout << i << '\n';
		}
	}

}

int main() {
	setIO("pprime");
	input();
	solve();
	output();
	return 0;
}