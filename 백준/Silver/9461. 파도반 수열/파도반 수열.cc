#include<iostream>

using namespace std;

long long b[101] = { 0,1,1,1 };



int main(){
	int num;
	cin >> num;

	for (int i = 4; i < 101; i++) {
		b[i] = b[i - 2] + b[i - 3];
	}
	
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		cout << b[a] << endl;
	}

	//p[n-2] + p[n-3]
}