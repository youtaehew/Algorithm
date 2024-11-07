#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int n, startNum = 1;
	cin >> n;
	vector<int> arr(n);
	stack<int> col;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++) {
		if (arr[i] == startNum) startNum++;
		else {
			col.push(arr[i]);
		}

		while (!col.empty() && col.top() == startNum) {
			col.pop();
			startNum++;
		}
	}
	
	if (col.empty()) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}


}