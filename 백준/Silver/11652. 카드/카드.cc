#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct info
{
	string name;
	int korean, english, math;
};

bool compare(info a, info b) {
	if (a.korean == b.korean && a.english == b.english && a.math == b.math) return a.name < b.name;
	else if (a.korean == b.korean && a.english == b.english) return a.math > b.math;
	else if (a.korean == b.korean) return a.korean < b.korean;
	else return a.korean > b.korean;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector<long long> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long currentCard = arr[0], maxCard = arr[0];
	int maxCount = 1;
	int currentCount = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == currentCard) {
			currentCount++;
		}
		else {
			currentCard = arr[i];
			currentCount = 1;
		}

		if (currentCount > maxCount) {
			maxCard = arr[i];
			maxCount = currentCount;
		}
	}

	cout << maxCard;
}
