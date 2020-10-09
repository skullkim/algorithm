#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const int INF = 1e6 + 10;
	int seq_len;
	cin >> seq_len;
	vector<int> seq(INF + 1);
	vector<int> num_freq(INF + 1, 0);
	for(int i = 1; i <= seq_len; i++){
		cin >> seq[i];
		num_freq[seq[i]]++;
	}
	vector<int> ans(INF + 1);
	stack<int> curr_max;
	curr_max.push(INF);
	for(int i = seq_len; i >= 1; i--){
		while(curr_max.top() != INF && num_freq[curr_max.top()] <= num_freq[seq[i]]) curr_max.pop();
		if(curr_max.top() >= INF) ans[i] = -1;
		else ans[i] = curr_max.top();
		curr_max.push(seq[i]);
	}
	for(int i = 1; i <= seq_len; i++) cout << ans[i] << " ";
}
