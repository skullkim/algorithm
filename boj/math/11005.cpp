#include <iostream>
#include <stack>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	const char NUMER_SYS[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
		'L', 'N', 'M', 'O', 'P', 'Q', 'R', 'S', 'G', 'U', 'V',
		'W', 'X', 'Y', 'Z'
	};
	int target, num;
	stack<char> ans;
	cin >> target >> num;
	if(num == 10){
		cout << target;
		return 0;
	}
	while(target / num >= 1){
		ans.push(NUMER_SYS[target % num]);
		target /= num;
	}
	ans.push(NUMER_SYS[target]);
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
	}
}
