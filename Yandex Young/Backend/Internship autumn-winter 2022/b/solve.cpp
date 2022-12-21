#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 2e5 + 5;

struct rocket {
	int day;
	int hour;
	int minute;
	int id;
	char status;
};

bool cmp(rocket a, rocket b) {
	if (a.day < b.day) return 1;
	else if (a.day == b.day) {
		if (a.hour < b.hour) return 1;
		else if (a.hour == b.hour) {
			if (a.minute < b.minute) return 1;
			return 0;
		}
		return 0;
	}
	return 0;
}

void solve() {          
	int n;
	cin >> n;
	vector<rocket> a(n);
	for (int i = 0; i < 8; i++) {
		cin >> a[i].day >> a[i].hour >> a[i].minute >> a[i].id >> a[i].status;
	}
	
	sort(a.begin(), a.end(), cmp);
//	cout << '\n';
	
	for (int i = 0; i < n; i++) {
		cout << a[i].day << ' ' << a[i].hour << ' ' << a[i].minute << ' ' << a[i].id << ' ' << a[i].status << '\n';
	}

	//return;

	map<int, pair<pair<int, int>, int>> rk;
	map<int, int> tot;

	for (int i = 0; i < n; i++) {
		int d = a[i].day, h = a[i].hour, m = a[i].minute, id = a[i].id, st = a[i].status;
		if (st == 'S' || st == 'C') {
			int uakit = 0;
			uakit += m + h * 60 + d * 24 * 60;
			m = rk[id].f.f;
			h = rk[id].f.s;
			m = rk[id].s;
			uakit -= m + h * 60 + d * 24 * 60;
			tot[id] += uakit;
		}
		else if (st == 'A') {
			rk[id] = mp(mp(d, h), m);
		}
	}

	for (auto it : tot) {
		cout << it.s << ' ';
	}
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
