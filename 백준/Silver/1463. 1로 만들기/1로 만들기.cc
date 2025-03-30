#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a;
	cin >> a;
	vector<int> dp(a + 1);

	for (int i = 2; i <= a; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}

		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}

	cout << dp[a];
}
