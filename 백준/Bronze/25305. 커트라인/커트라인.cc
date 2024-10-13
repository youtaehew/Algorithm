#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, victory,key, j;
	vector<int> num;

	cin >> n >> victory;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	//85624 56824

	for (int i = 1; i < num.size(); i++) {
		key = num[i]; 
		for (j = i - 1; j >= 0; j--) {
			if (num[j] > key) {
				num[j + 1] = num[j];
			}
			else {
				break;
			}
		}
		num[j + 1] = key;
	}

	cout << num[n - victory];
}