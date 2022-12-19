#include<bits/stdc++.h>

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

bool usedCow[100], usedPos[100];
int pos[100];

int nCows, M, nFixed;

int ord[100];

int cFixed[101], pFixed[101];

bool works() {
	for (int i = 0; i < nCows; i++) 
		usedCow[i] = usedPos[i] = 0;
	for (int i = 0; i < nFixed; i++) {
		if (usedCow[cFixed[i]] && pos[cFixed[i]] == pFixed[i]) continue;
		if (usedCow[cFixed[i]]) return 0;
		if (usedPos[pFixed[i]]) return 0;
		usedCow[cFixed[i]] = 1;
		usedPos[pFixed[i]] = 1;
		pos[cFixed[i]] = pFixed[i];
	}	
	int j = 0;
	for (int i = 0; i < M; i++) {
		int cow = ord[i];
		if (usedCow[cow]) {
			if (j > pos[cow]) return 0;
			j = pos[cow];
			continue;
		}
		while (usedPos[j]) {
			j++;
			if (j == nCows) return 0;
		}
		usedPos[j] = 1;
		pos[cow] = j;
	}
	return 1;
}

void solve() {        
	cin >> nCows >> M >> nFixed;
	for (int i = 0; i < M; i++) {
		cin >> ord[i];
		ord[i]--;
	}
	for (int i = 0; i < nFixed; i++) {
		cin >> cFixed[i] >> pFixed[i];
		cFixed[i]--, pFixed[i]--;
	}
	nFixed++;
	for (int i = 0; i < nCows; i++) {
		cFixed[nFixed - 1] = 0;
		pFixed[nFixed - 1] = i;
		if (works()) {
			cout << i + 1 << '\n';
			return;
		}
	}
}

int main() {
	setIO("milkorder");
	solve();
	return 0;
}