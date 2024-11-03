#include<iostream>
#include<vector>	
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int count, max;
	cin >> count >> max;
	vector<int> arr(count);
	int maxsum = 0;
	for (int i = 0; i < count; i++) {
		int b;
		cin >> b;
		arr[i] = b;
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (i == j) continue;

			for (int k = 0; k < count; k++) {
				if (k == i || k == j) continue;
				int sum = arr[i] + arr[j] + arr[k];
				if (sum > maxsum && sum <= max)
					maxsum = sum;
			}
		}
	}

	cout << maxsum;

}