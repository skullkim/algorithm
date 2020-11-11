#include <iostream>
#include <stack>
#include <deque>
#include <map>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//operator priority:
	//0:(), 1:*_/, 2:+_-
	map<char, int> ope_priority;
	ope_priority['*'] = 1; ope_priority['/'] = 1;
	ope_priority['+'] = 2; ope_priority['-'] = 2;
	ope_priority['('] = 3; ope_priority[')'] = 3;
	string formular;
	cin >> formular;
	stack<char> operators;
	for(int i = 0; i < formular.size(); i++){
		if('A' <= formular[i] && formular[i] <= 'Z') cout << formular[i];
		else if(formular[i] ==  '(') operators.push(formular[i]);
		else if(formular[i] == ')'){
			while(operators.top() != '('){
				cout << operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else{
			while(!operators.empty() && ope_priority[operators.top()] <= ope_priority[formular[i]]){
				cout << operators.top();
				operators.pop();
			}
			operators.push(formular[i]);
		}
	}
	while(!operators.empty()){
		cout << operators.top();
		operators.pop();
	}
}
