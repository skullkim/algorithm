#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NUM = 12;
int cache[MAX_NUM], num;

void calAllPosibility(int curr_num){
	if(curr_num > num) return;
	cache[curr_num] = cache[curr_num - 1] + cache[curr_num - 2] + cache[curr_num - 3];
	calAllPosibility(curr_num + 1);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		memset(cache, 0, sizeof(cache));
		cin >> num;
		cache[0] = 0; cache[1] = 1;
		cache[2] = 2; cache[3] = 4;
		calAllPosibility(4);
		cout << cache[num] << "\n";
	}
}
