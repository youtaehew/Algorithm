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

	/*vector<vector<int>> dp(n + 1, vector<int>(10, 0));*/
	vector<long long> dp(n + 1);
	
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
	
		
}
