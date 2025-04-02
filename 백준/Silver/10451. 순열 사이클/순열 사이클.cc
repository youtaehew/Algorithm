#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

bool visited[1001];
vector<int> arr[1001];
int cycle;

void DFS(int v) {
	visited[v] = true;
	if (!visited[arr[v][0]]) {
		DFS(arr[v][0]);
	}
	else {
		cycle++;
	}

}

int main() {
	int n;
	cin >> n;

	while (n--) {
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		cycle = 0;

		int k;
		cin >> k;

		for (int i = 1; i <= k; i++) {
			int a;
			cin >> a;
			arr[i].push_back(a);
		}
		for (int i = 1; i <= k; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		cout << cycle << endl;
	}
	
}