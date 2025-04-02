#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAX_NUM 3000001
using namespace std;

vector<vector<int>> arr;
vector<int> house;
int n;

int result;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void DFS(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || arr[x][y] == 0) return;
	arr[x][y] = 0;
	result++;

	for (int i = 0; i < 4; i++) {
		DFS(x + dx[i], y + dy[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	arr.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < n; j++) {
			arr[i][j] = row[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = arr[i][j];
			if (x == 1) {
				result = 0;
				DFS(i, j);
				house.push_back(result);
			}
		}
	}
	cout << house.size() << "\n";
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << "\n";
	}
}
