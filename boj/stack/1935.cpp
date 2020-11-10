#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(void){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int len;
	string formular;
	cin >> len >> formular;
	double nums[len];
	for(int i = 0; i < len; i++){
		cin >> nums[i];
	}
	stack<double> ans;
	for(int i = 0; i < formular.size(); i++){
		if('A' <= formular[i] && formular[i] <= 'Z') ans.push(nums[formular[i] - 'A']);
		else if(ans.size() >= 2){
			double arr[2];
			for(int i = 1; i >= 0; i--){
				arr[i] = ans.top();
				ans.pop();
			}
			double tmp_ans = arr[0];
			switch (formular[i]){
				case '+':
					tmp_ans += arr[1];
					break;
				case '-':
					tmp_ans -= arr[1];
					break;
				case '/':
					tmp_ans /= arr[1];
					break;
				case '*':
					tmp_ans *= arr[1];
					break;
			}
			ans.push(tmp_ans);
		}
	}
	printf("%.2lf", ans.top());
//	cout.precision(3);
//	cout << ans.top();
}
