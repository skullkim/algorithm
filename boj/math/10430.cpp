#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) % c << "\n"
		<< ((a % c) + (b % c)) % c << "\n"
		<< (a * b) % c << "\n"
		<< ((a % c) * (b % c)) % c << "\n";
}
