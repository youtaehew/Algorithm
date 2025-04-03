#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string arr;
	stack<int> log;

	int totalCnt = 0;

	cin >> arr;

	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == '(') {
			log.push(arr[i]);
		}
		else {
			if (arr[i - 1] == '(') {
				log.pop();
				totalCnt += log.size();
			}
			else {
				totalCnt++;
				log.pop();
			}
		}
	}

	cout << totalCnt;
	
}
