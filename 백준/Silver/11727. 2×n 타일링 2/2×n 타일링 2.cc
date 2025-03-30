#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int a;
	cin >> a;
	vector<int> dp(a + 1);

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= a; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[a] ;
}
