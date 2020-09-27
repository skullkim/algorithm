#include <iostream>
#include <vector>
using namespace std;
const int THREE = 3;
const int MAX_NUM = 1000;
int target, cases = 0;


void findAllCases(int curr_num, int used){
	if(used == THREE - 1){
		if((target - curr_num) > 0 && (target - curr_num) % THREE == 0){
			cases++;
		}
		return;
	}
	for(int i = 1; i <= MAX_NUM; i++){
		if(curr_num + i * THREE > target) return;
		findAllCases(curr_num + i * THREE, used + 1);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> target;
	findAllCases(0, 0);
	cout << cases;
}
