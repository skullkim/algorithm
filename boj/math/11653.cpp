#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_NUM = 1e7 + 5;
	int num;
	cin >> num;
	for(int i = 2; i < MAX_NUM && num >= 2; i++){
		while(!(num % i)){
			cout << i << "\n";
			num /= i;
		}
	}
}
