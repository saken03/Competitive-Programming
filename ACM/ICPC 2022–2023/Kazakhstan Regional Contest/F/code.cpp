/***
    AUTHOR:    shabylkhan
    CREATED:   29.10.2022 16:02:27

***/

#include<bits/stdc++.h>

using namespace std;

// sin cos tan asin acos atan
// 0   1    2   3    4    5

vector<int> p;
string trig[] = {"sin", "cos", "tan", "asin", "acos", "atan"};

void rec(double a, double b) {
	if (a == b) {
		return;
	}

	p.push_back(0);
	rec(sin(a), b);
	p.pop_back();

	p.push_back(1);
	rec(cos(a), b);
	p.pop_back();

	p.push_back(2);
	rec(tan(a), b);
	p.pop_back();

	p.push_back(3);
	rec(asin(a), b);
	p.pop_back();

	p.push_back(4);
	rec(acos(a), b);
	p.pop_back();

	p.push_back(5);
	rec(atan(a), b);
	p.pop_back();
}

void solve() {
	set<double> s;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			s.insert((double)i / j);
		}
	}
	cout << (int)s.size() << '\n';
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}

/*
	int a, b;
	cin >> a >> b;

	double aim = a / b;
	rec(0.0, aim);
	cout << (int)p.size() << '\n';
	for (int i = 0; i < (int)p.size(); i++) {
		cout << trig[p[i]] << ' ';
	}
	cout << '\n';
*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	while (tt--) {
		solve();
	}

	return 0;
} 