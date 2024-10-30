#include<iostream>
#include<vector>

using namespace std;

int col[15];
int n, total = 0;

bool Check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] == col[level] || abs(col[i] - col[level]) == level - i) {
			return false;
		}
	}
	return true;
}

void BackTracking(int x) {
	if (x == n) {
		total++;
		return;
	}
	for (int i = 0; i < n; i++) {
		col[x] = i;
		if (Check(x)) {
			BackTracking(x + 1);
		}
	}
}

int main() {
	cin >> n;
	BackTracking(0);
	cout << total;
}