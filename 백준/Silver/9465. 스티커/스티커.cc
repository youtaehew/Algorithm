#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int count;
	cin >> count;

	while (count--) {
		int n;
		cin >> n;

		vector<vector<int>> dp(2, vector<int>(n + 1, 0));
		vector<vector<int>> arr(2, vector<int>(n + 1, 0));

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
	
}