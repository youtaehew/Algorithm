#include<iostream>
#include<vector>	
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main() {
	set<char> group;
	bool istrue;
	int n, count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		group.clear();
		istrue = true;
		for (int i = 0; i < a.length(); i++) {
			if (i >= 1 && a[i] != a[i - 1] && group.count(a[i])) {
				istrue = false;
				break;
			}
			group.insert(a[i]);
		}
		if(istrue)
			count++;
	}
	cout << count;

}