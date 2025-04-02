#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
struct tomatos
{
	int x, y;
};
queue<tomatos> q;

int w, h;
vector<vector<int>> arr;
int days = 0;
bool can = true;

void DFS(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w || arr[x][y] == 0) return;

	arr[x][y] = 0;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		DFS(nx, ny);
	}
}

void BFS() {
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++) {
			tomatos tomato = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = tomato.x + dx[j];
				int ny = tomato.y + dy[j];

				if (nx >= 0 && nx < h && ny >= 0 && ny < w && arr[nx][ny] == 0) {
					arr[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
		days++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> w >> h;
	arr.resize(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	BFS();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 0) {
				can = false;
				break;
			}
		}
	}

	if (can)
		cout << days - 1;
	else
		cout << -1;
}
