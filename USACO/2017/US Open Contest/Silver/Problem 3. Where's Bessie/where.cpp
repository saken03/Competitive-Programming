/***
PROB: 
LANG: C++14
username: sakenseri1
***/
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

const int N = 20;
vector<vector<char>> image(N, vector<char>(N));
vector<vector<bool>> visited(N, vector<bool>(N));

struct PCL {
	int i1, j1;
	int i2, j2;

	bool is_inside(PCL other) {
		return (
			i1 >= other.i1 &&
			i2 <= other.i2 &&
			j1 >= other.j1 &&
			j2 <= other.j2
		);
	}
};

int i_min, i_max, j_min, j_max;
void floodfill(int i, int j, int color) {
	if (
		i < i_min || j < j_min || i > i_max || j > j_max ||
		visited[i][j] ||
		image[i][j] != color
	) return;

	visited[i][j] = 1;

	floodfill(i + 1, j, color);
	floodfill(i - 1, j, color);
	floodfill(i, j + 1, color);
	floodfill(i, j - 1, color);
}

bool is_pcl(int i1, int j1, int i2, int j2) {
	vector<int> region_count(26);

	i_min = i1;
	i_max = i2;
	j_min = j1;
	j_max = j2;

	for (int i = i1; i <= i2; i++) 
		for (int j = j1; j <= j2; j++) 
			if (!visited[i][j]) {
				char curr_color = image[i][j];
				region_count[curr_color - 'A']++;
				floodfill(i, j, curr_color);
			}

	fill(visited.begin(), visited.end(), vector<bool>(N));

	int color_count = 0;
	bool color_with_one_region = false;
	bool color_with_more_regions = false;
	for (int i = 0; i < sz(region_count); i++) {
		if (region_count[i] != 0)
			color_count++;
		if (region_count[i] == 1) 
			color_with_one_region = true;
		if (region_count[i] > 1)
			color_with_more_regions = true;
	}

	return (
		color_count == 2 &&
		color_with_one_region &&
		color_with_more_regions
	);
}

void solve() {        
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> image[i][j];

	vector<PCL> pcl_list;
	for (int i1 = 0; i1 < n; i1++) 
		for (int j1 = 0; j1 < n; j1++) 
			for (int i2 = 0; i2 < n; i2++) 
				for (int j2 = 0; j2 < n; j2++) 
					if (is_pcl(i1, j1, i2, j2)) 
						pcl_list.pb({i1, j1, i2, j2});

	int pcl_count = 0;
	for (int i = 0; i < sz(pcl_list); i++) {
		bool valid_pcl = true;
		for (int j = 0; j < sz(pcl_list); j++) {
			if (i == j) 
				continue;
			if (pcl_list[i].is_inside(pcl_list[j])) {
				valid_pcl = false;
				break;
			}
		}
		pcl_count += valid_pcl;
	}

	cout << pcl_count << '\n';
}

int main() {
	setIO("where");

	solve();

	return 0;
}   
