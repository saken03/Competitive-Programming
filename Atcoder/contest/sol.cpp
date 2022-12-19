/***
    AUTHOR:    shabylkhan
    CREATED:   18.06.2022 18:07:25

***/

#include<bits/stdc++.h>

using namespace std;

struct wh {
	int h1, h2, h3;
	int w1, w2, w3;
};

int cnt;

template<typename T>
template<typename E>

void rec(T a, E tb) {
	
}

void solve() {
	wh tb;
	cin >> tb.h1 >> tb.h2 >> tb.h3 >> tb.w1 >> tb.w2 >> tb.w3;

	vector<vector<int>> a(3, vector<int> (3, -1));

	rec(a, tb);
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