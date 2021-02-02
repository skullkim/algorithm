#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> st;
	int m, idx;
	cin >> idx;
	st.push(1e7);
	vector<int> v(idx), an(idx);
	for(int i =0 ; i < idx; i++){
		cin >> v[i];
	}
	for(int i = idx - 1; i >= 0; i--){
		while(st.top() < v[i]) st.pop();
		if(st.top() == 1e7) an[i] = -1;
		else an[i] = st.top();
		st.push(v[i]);
	}
	for(int i = 0; i < an.size(); i++) cout << an[i] << " ";
}