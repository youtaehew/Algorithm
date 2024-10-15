#include<iostream>

using namespace std;

int fibo[46] = { 0 ,1,1};  

int f(int n) {
    if (fibo[n] != 0) return fibo[n];  
    fibo[n] = f(n - 1) + f(n - 2); 
    return fibo[n]; 
}

int main(void) {
    int n;
    cin >> n;
    cout << f(n); 
}