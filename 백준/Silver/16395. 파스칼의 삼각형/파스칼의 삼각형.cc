#include<iostream>

using namespace std;

int main() {
	int x, y;
	int arr[100][100] = {};

	cin >> x >> y;

	int big = x > y ? x : y;

	for (int i = 1; i <= big; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || i <=2)
				arr[j][i] = 1;
			else {
				arr[j][i] = arr[j][i-1] + arr[j-1][i - 1];
			}
		}
	}

	cout << arr[y][x];
}