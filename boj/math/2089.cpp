#include <iostream>
#include <stack>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int deci;
	stack<int> ans;
	cin >> deci;
	if(!deci){
		cout << 0;
		return 0;
	}
	while(deci){
		int left = deci % -2;
		deci /= -2;
		if(left < 0){
			ans.push(1);
			deci++;
		}
		else ans.push(left);
	}
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
	}
}
