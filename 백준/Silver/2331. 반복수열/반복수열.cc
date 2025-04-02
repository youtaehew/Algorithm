#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

#define MAX_NUM 3000001
using namespace std;

int visited[MAX_NUM];
int mul;
int result = 0;

int SumPow(int n) {
	int sum = 0;
	while (n > 0)
	{
		int k = n % 10;
		sum += (int)pow(k, mul);
		n /= 10;
	}
	return sum;
}

void DFS(int v) {
	visited[v]++;
	if (visited[v] == 3) return;
	int next = SumPow(v);
	DFS(next);
}

int main() {
	int num;
	cin >> num >> mul;
	DFS(num);
	for (int i = 0; i < MAX_NUM; i++) {
		if (visited[i] == 1) {
			result++;
		}
	}
	cout << result;
}
