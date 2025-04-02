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
	else if (a.korean == b.korean) return a.english < b.english;
	else return a.korean > b.korean;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<info> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].name << "\n";
	}
}
