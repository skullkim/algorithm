#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN = 1e4 + 10;
const int MOD = 1e4 + 7;
int cache[MAX_LEN];

int fillTile(int curr_len){
	if(curr_len <= 1) return 1;
	int & tmp = cache[curr_len];
	if(tmp) return tmp;
	return tmp = (fillTile(curr_len - 1) +  fillTile(curr_len - 2)) % MOD; 
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	cin >> len;
	cout << fillTile(len);
}
