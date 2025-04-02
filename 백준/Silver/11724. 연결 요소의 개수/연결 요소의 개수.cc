#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> arr[1001];
bool visited[1001];

void DFS(int v) {
	//cout << v << " ";
	visited[v] = true;
	for (int i = 0; i < arr[v].size(); i++) {
		int next = arr[v][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;


	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a << " ";

		for (int i = 0; i < arr[a].size(); i++) {
			int b = arr[a][i];
			if (!visited[b]) {
				q.push(b);
				visited[b] = true;
			}
		}
	}
}

int main() {
	int n, m;
	int total = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
			total++;
		}
	}

	cout << total;
	
}