#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long sum = 0;
	int n;
	cin >> n;
	vector<vector<int>>dp(n+1, vector<int>(10, 0));

	dp[1] = { 0,1,1,1,1,1,1,1,1,1 };

	for (int i = 2; i <= n; i++) 
	{
		for (int j = 0; j <= 9; j++) 
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++) 
	{
		sum += dp[n][i];
		sum %= 1000000000;
	}

	cout << sum;
		
}
