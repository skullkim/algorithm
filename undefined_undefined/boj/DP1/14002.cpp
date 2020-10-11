#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int MAX_LEN = 1e3 + 10;
	int len, cache[MAX_LEN], seq[MAX_LEN];
	memset(cache, 0, sizeof(cache));
	cin >> len;
	vector<int>lis;
	for(int i = 0; i < len; i++) cin >> seq[i];
	lis.push_back(seq[0]);
	for(int i = 1; i < len; i++){
		if(seq[i] <= lis.back()){
			auto change = lower_bound(lis.begin(), lis.end(), seq[i]);
			*change = seq[i];
		}
		else lis.push_back(seq[i]);
	}
	cout << lis.size() << "\n";
	for(int i = 0; i < lis.size(); i++) cout << lis[i] << " ";
}
