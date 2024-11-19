#include<iostream>
#include<deque>
#include<vector>

using namespace std;


int main() {
	
	int n, money;
	cin >> n >> money;
	
	vector<int> coin(n);
	vector<int> dp(money + 1);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int co : coin) {
		for (int i = co; i <= money; i++) {
			dp[i] += dp[i-co];
		}
	}

	cout << dp[money];
}