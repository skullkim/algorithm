#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_LEN = 1e3 + 10;
int seq[MAX_LEN], change[MAX_LEN];
vector<int> lis;

void findNextEle(int curr_idx){
	if(curr_idx == -1) return;
	lis.push_back(seq[curr_idx]);
	findNextEle(change[curr_idx]);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	cin >> len;
	for(int i = 0; i < len; i++) cin >> seq[i];
	int cache[MAX_LEN];
	memset(cache, 0, sizeof(cache));
	memset(change, -1, sizeof(change));
	int lis_len = 0;
	for(int i = 0; i < len; i++){
		cache[i] = 1;
		for(int k = 0; k < i; k++){
			if(seq[i] > seq[k] && cache[i] < cache[k] + 1){
				cache[i] = cache[k] + 1;
				change[i] = k;
			}
		}
		lis_len = max(lis_len, cache[i]);
	}
	for(int i = 0; i < len; i++){
		if(cache[i] == lis_len){
			lis.push_back(seq[i]);
			findNextEle(change[i]);
		}
	}
	sort(lis.begin(), lis.end());
	cout << lis_len << "\n";
	for(int i = 0; i < lis.size(); i++) cout << lis[i] << " ";
}
