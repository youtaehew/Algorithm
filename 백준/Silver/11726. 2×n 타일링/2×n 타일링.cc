#include<iostream>

using namespace std;

int fibo[1001] = { 0,1,2,3 };
int count = 0;

int f(int n) {
	if (n <= 3 || fibo[n] != 0) {
		return fibo[n];
	}
	fibo[n] = (f(n - 1) + f(n - 2)) % 10007;
	return fibo[n];
}

int main() {
	int a;
	cin >> a;
	int c = f(a);
	cout << c;
}