#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> dp(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];
	
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 1], arr[i])));
	}

	cout << max(dp[n], dp[n - 1]);
}