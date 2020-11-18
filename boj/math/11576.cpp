#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int numer_sys_A, numer_sys_B;
	int len;
	cin >> numer_sys_A >> numer_sys_B >> len;
	string target;
	int tmp = 0, num;
	for(int i = len - 1; i >= 0; i--){
		cin >> num;
		tmp += num * pow(numer_sys_A, i);
	}
	stack<int> ans;
	while(tmp){
		int left = tmp % numer_sys_B;
		ans.push(left);
		tmp /= numer_sys_B;
	}
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
}
