#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, result = 0;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(10, 0));

	dp[1] = { 1,1,1,1,1,1,1,1,1,1 };

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += dp[n][i];
	}

	cout << result % 10007;
		
}
