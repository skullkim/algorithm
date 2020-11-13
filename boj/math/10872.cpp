#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	long long pac = 1;
	cin >> num;
	while(num >= 1) pac *= num--;
	cout << pac;
}
