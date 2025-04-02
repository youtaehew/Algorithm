#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

#define MAX_NUM 3000001
using namespace std;
int arr[100001];
bool visited[100001];
bool isTeam[100001];
int result = 0;

void DFS(int v) {
	visited[v] = true;
	int next = arr[v];

	if (!visited[next]) {
		DFS(next);
	}
	else if (!isTeam[next]) { 
		for (int i = next; i != v; i = arr[i]) {
			result++;
		}
		result++;
	}
	isTeam[v] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int k;
	cin >> k;

	while (k--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				DFS(i);
		}

		cout << n - result << "\n";
		result = 0;
		memset(visited, 0, sizeof(visited));
		memset(isTeam, false, sizeof(isTeam));
	}
}
