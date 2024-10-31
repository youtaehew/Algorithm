#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	vector<int> a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		a.push_back(c);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		cout << a[i] <<"\n";
	}
}