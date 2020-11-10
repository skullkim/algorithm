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
	ope_priority['('] = 0; ope_priority[')'] = 0;
	ope_priority['*'] = 1; ope_priority['/'] = 1;
	ope_priority['+'] = 2; ope_priority['-'] = 2;
	string formular;
	cin >> formular;
	deque<char> ans;
	stack<char> operators;
	for(int i = 0; i < formular.size(); i++){
		if('A' <= formular[i] && formular[i] <= 'Z') ans.push_back(formular[i]);
		else if(operators.empty()) operators.push(formular[i]);
		else{
			if(formular[i] == '('){
				i++;
				while(formular[i] != ')'){
					'A' <= formular[i] && formular[i] <= 'Z' ? ans.push_back(formular[i]) : operators.push(formular[i]);
					i++;
				}
			}
			else if(ope_priority[operators.top()] > ope_priority[formular[i]]){
				operators.push(formular[i]);
			}
			else if(ope_priority[operators.top()] <= ope_priority[formular[i]]){
				while(!operators.empty()){
					ans.push_back(operators.top());
					operators.pop();
				}
				operators.push(formular[i]);
			}
		}
	}
	while(!operators.empty()){
		ans.push_back(operators.top());
		operators.pop();
	}
	while(!ans.empty()){
		cout << ans.front();
		ans.pop_front();
	}
}
