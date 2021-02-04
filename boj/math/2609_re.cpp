#include <iostream>
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
	return a * b / gcd(a, b);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << "\n";
	cout << lcm(a, b);
}