#include<bits/stdc++.h>

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
                
typedef long long ll;

using namespace std;

const int MAXN = 10005;

string f, i, o;
int d, m, y;

void process(string s) {
	vector<string> v;
	string cur = "";
	s += ',';
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == ',') {
			v.pb(cur);
			cur = "";
		}
		else cur += s[i];
	}

	f = v[0];
	i = v[1];
	o = v[2];

	s = v[3];
	for (int i = 0; i < sz(s); i++) {
		d *= 10;
		d += s[i] - '0';
	}
	s = v[4];
	for (char i : s) {
		m *= 10;
		m += i - '0';
	}
	s = v[5];
	for (char i : s) {
		y *= 10;
		y += i - '0';
	}
}

void solve() {          
	string s;
	cin >> s;            
	
	process(s);

	string fio = f + i + o;
	map<char, bool> cnt_fio;
	for (char c : fio) cnt_fio[c] = 1;

	int cnt_dm = 0;
	while (d) {
		cnt_dm += d % 10;
		d /= 10;
	}
	while (m) {
		cnt_dm += m % 10;
		m /= 10;
	}

	cnt_dm *= 64;

	int cnt_no = 0;
	if (f[0] >= 'a' && f[0] <= 'z') cnt_no = f[0] - 'a' + 1;
	else cnt_no = f[0] - 'A' + 1;
	
	cnt_no *= 256;

	int sum = sz(cnt_fio) + cnt_dm + cnt_no;

	string hex = "";
	while (sum) {
		if (sum % 16 > 9) {
			hex += (sum % 16) - 10 + 'A';
		}
		else {
			hex += sum % 16 + '0';
		}
		sum /= 16;
	}

	while (sz(hex) < 3) {
		hex += '0';
	}
	hex = hex.substr(0, 3);  
	reverse(hex.begin(), hex.end());
	cout << hex << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
} 
