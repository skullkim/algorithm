#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	cin >> len;
	vector<int> sequence(len);
	vector<char> ans;
	stack<int> s1, s2;
	for(int i = 0; i < len; i++) cin >> sequence[i];
	int seq_idx = 0;
	for(int i = 1; i <= len; i++){
		s1.push(i);
		ans.push_back('+');
		if(s1.top() == sequence[seq_idx]){
			while(!s1.empty() && s1.top() == sequence[seq_idx]){
				s2.push(s1.top());
				s1.pop();
				ans.push_back('-');
				seq_idx++;
			}
		}
	}
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
		ans.push_back('-');
	}
	for(int i = len - 1; i >= 0 && !s2.empty(); i--){
		if(sequence[i] != s2.top()){
			cout << "NO";
			return 0;
		}
		s2.pop();
	}
	for(auto i : ans) cout << i << "\n";
}
