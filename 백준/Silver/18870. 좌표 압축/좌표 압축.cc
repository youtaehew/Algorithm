#include<iostream>
#include<vector>	
#include<algorithm>
#include<string>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> arr2(n);

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		arr[i] = b;
	}
	arr2 = arr;
	
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(arr.begin(), arr.end(), arr2[i]) - arr.begin() << " ";
	}

}