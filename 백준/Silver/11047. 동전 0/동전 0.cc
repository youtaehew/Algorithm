#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>	

using namespace std;


int main() {
	int n, money;
	cin >> n >> money;
	int count = 0;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	for (int i = n-1 ; i >= 0; i--) {
		if (money - coins[i] >= 0) {
			int b = money / coins[i];
			count += b;
			money -= b * coins[i];
		}
		if (!money) break;
	}

	cout << count;
}