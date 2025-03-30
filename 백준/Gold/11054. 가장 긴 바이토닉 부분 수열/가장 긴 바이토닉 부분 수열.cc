#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> LeftToRight(n, 1);
	vector<int> RightToLeft(n, 1);
	vector<int> dp(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		LeftToRight[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				LeftToRight[i] = max(LeftToRight[i], LeftToRight[j] + 1);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		RightToLeft[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j])
				RightToLeft[i] = max(RightToLeft[i], RightToLeft[j] + 1);
		}
	}

	int maxLength = 0;
	for (int i = 0; i < n; i++) {
		maxLength = max(maxLength, LeftToRight[i] + RightToLeft[i] - 1);
	}

	cout << maxLength;
}
