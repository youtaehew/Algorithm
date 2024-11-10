#include<iostream>
#include<deque>

using namespace std;

deque<pair<int, int>> balloons;
int n;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		balloons.push_back({ i,a });
	}

	while (!balloons.empty()) {
		auto current = balloons.front();
		cout << current.first << " ";
		balloons.pop_front();

		if (balloons.empty()) break;
		int step = current.second;

		if (step > 0) {
			for (int i = 1; i < step; i++) {
				balloons.push_back(balloons.front());
				balloons.pop_front();
			}
		}
		else {
			for (int i = 0; i < -step; i++) {
				balloons.push_front(balloons.back());
				balloons.pop_back();
			}
		}


	}
}